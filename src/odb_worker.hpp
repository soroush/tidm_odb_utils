/*
 * libtidm_common - Common tools and utilities of the TIDM/OI
 * Copyright (C) 2017 TIDM Co.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef TIDM_ODB_WORKER_HPP
#define TIDM_ODB_WORKER_HPP

#include "odb_stat.hpp"
#include <sstream>
#include <deque>
#include <mutex>
#include <atomic>
#include <vector>
#include <functional>
#include <chrono>
#include <thread>
#include <cstddef>
#include <limits>
#include <tidm/utils/exception/exception.hpp>
#include <tidm/utils/common/semaphore.hpp>
#include <odb/database.hxx>

#define  MAX_POOL_SIZE  100
#define  MAX_COMMIT_TIMEOUT  60
#define  MAX_COMMIT_COUNT  10000
#define  MAX_QUE_SIZE  100000000

namespace tidm {
struct odb_worker_param {
    std::size_t max_que_size;
    int pool_size;
    int commit_count;
    int commit_timeout; // second
    odb_worker_param();
    std::string to_string()const;
};

std::ostream operator<<(std::ostream &os, const odb_worker_param &prm);

class odb_worker_base {
    public:
        enum class state {NEW, READY, TERMINATED};
        odb_worker_base();
        virtual ~odb_worker_base() = default;
        virtual void init(odb::database *db,
                          const odb_worker_param &prm,
                          std::function<void(tidm::exception)>handler) throw(tidm::exception);
        virtual void worker() = 0;
        virtual odb_stat get_stat() throw();
        void finalize() throw();
    protected:
        std::atomic<state> _state;
        odb_worker_param _init_param;
        odb::database *_db;

        tidm::semaphore _sem;
        std::mutex _que_gurad;

        std::vector<std::thread> _worker_threads;
        std::function<void(tidm::exception)> _exception_handler;

        odb_stat _stat;
        std::mutex _stat_gurad;
    private:
        odb_worker_base(const odb_worker_base &); //is PRIVATE to avoid pass by value - no body_base
        odb_worker_base &operator=(const odb_worker_base &); //is PRIVATE to avoid assigning - no body
};

template<class T>
class odb_worker: public odb_worker_base {
    public:
        std::function<void(tidm::exception, const T &obj)> _local_exception_handler;
        std::function<void(const T &)>  _post_handler;
        void init(odb::database *db,
                  const odb_worker_param &prm,
                  std::function<void(tidm::exception)>  handler
                 ) throw(tidm::exception) {
            odb_worker_base::init(db, prm, handler);
        }


        void init(odb::database *db,
                  const odb_worker_param &prm,
                  std::function<void(tidm::exception, const T &obj)>  local_handler,
                  std::function<void(tidm::exception)>  handler,
                  std::function<void(const T &)> post_handler

                 ) throw(tidm::exception) {
            if(_state != state::NEW) {
                throw tidm::exception(__FILE__, __FUNCTION__,
                                      "invalid odb_worker_base state(re-initialization or initialization of a finalized worker)");
            }
            if(db == nullptr) {
                throw tidm::exception(__FILE__, __FUNCTION__, "database pointer is null");
            }
            if(prm.pool_size <= 0 ||
                    prm.commit_count <= 0 ||
                    prm.commit_timeout <= 0 ||
                    prm.max_que_size <= 0 ||
                    prm.pool_size > MAX_POOL_SIZE ||
                    prm.max_que_size > MAX_QUE_SIZE ||
                    prm.commit_timeout > MAX_COMMIT_TIMEOUT ||
                    handler == nullptr
              ) {
                std::stringstream sstr;
                sstr << "invalid initialization parameter: " << prm.to_string().c_str()
                     << "  0 <= pool_size < " << MAX_POOL_SIZE
                     << "  0 <= commit_count < " << MAX_COMMIT_COUNT
                     << "  0 <= commit_timeout < " << MAX_COMMIT_TIMEOUT
                     << "  exception_handler != null ";
                throw tidm::exception(__FILE__, __FUNCTION__, sstr.str().c_str());
            }
            _local_exception_handler  = local_handler;
            _post_handler = post_handler;
            _exception_handler  = handler;
            _init_param = prm;
            _db = db;
            _state = state::READY;
            for(int i = 0; i < _init_param.pool_size; i++) {
                _worker_threads.emplace_back(&odb_worker_base::worker, this);
            }
        }


        odb_stat get_stat()throw() {
            odb_stat temp = odb_worker_base::get_stat();
            {
                std::lock_guard<std::mutex> m{_que_gurad};
                temp.set_que_len(_que.size());
            }
            return temp;
        }
        void persist(const T &obj)throw(tidm::exception) {
            if(_state != state::READY) {
                throw tidm::exception(__FILE__, __FUNCTION__, "invalid use of un-initilized/finalized worker");
            }
            {
                std::lock_guard<std::mutex> m{_que_gurad};
                if(_que.size() >= _init_param.max_que_size) {
                    throw tidm::exception(__FILE__, __FUNCTION__,
                                          (std::string("maximum queue size exceeded! max limit is ") + std::to_string(
                                               _init_param.max_que_size)).c_str());
                }
                T *p = new T(obj);
                _que.push_back(p);
            }
            _sem.notify();
        }
    private:
        std::deque<T *> _que;
        bool reconnect(odb::core::transaction *&trans) {
            while(_state == state::READY)  {
                try {
                    {
                        std::lock_guard<std::mutex> m{_stat_gurad};
                        _stat.update(0, execution_state::RECOVERING);
                    }
                    if(trans != nullptr) {
                        delete trans;
                    }
                    trans = nullptr;
                    trans = new odb::core::transaction(_db->begin());
                    break;
                } catch(...) {
                    trans = nullptr;
                }
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            if(_state != state::READY) {
                return false ;
            } else {
                return true;
            }

        }
        void do_persist(T *p) {
            auto start = std::chrono::high_resolution_clock::now();
            _db->persist(*p);
            auto end = std::chrono::high_resolution_clock::now();
            uint64_t diff_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            {
                std::lock_guard<std::mutex> m{_stat_gurad};
                _stat.update(diff_time, execution_state::SUCCESS);
            }
        }

        bool do_commit(
            std::chrono::high_resolution_clock::time_point &last_commit,
            int &commit_counter,
            odb::core::transaction *&trans,
            std::vector<T *> &uncommited
        ) {
            auto nw = std::chrono::high_resolution_clock::now();
            auto time_to_last_commit = std::chrono::duration_cast<std::chrono::seconds>(nw - last_commit).count();
            bool r  = true;
            if(time_to_last_commit >= _init_param.commit_timeout || commit_counter >= _init_param.commit_count) {
                try {
                    trans->commit();
                    for(auto i : uncommited) {
                        if(i != nullptr) {
                            delete i;
                        }
                    }
                    uncommited.clear();
                    commit_counter = 0;
                    last_commit = nw;
                    trans->reset(_db->begin());
                } catch(odb::exception &ox) {
                    r = reconnect(trans);
                }
            }
            return r;
        }
        void worker() {
            //   T obj;
            T *p = nullptr;
            T p2;
            std::vector<T *> uncommited;
            bool wait_res = false;
            odb::core::transaction *trans = nullptr;
            try {
                trans = new odb::core::transaction(_db->begin());
                int commit_counter = 0;
                auto last_commit = std::chrono::high_resolution_clock::now();
                auto last_shrink = std::chrono::high_resolution_clock::now();

                bool persisted = true;
                //start of main LOOP
                while(_state == state::READY) {
                    wait_res = _sem.wait_for(std::chrono::milliseconds(100));
                    if(_state != state::READY) {//someone has called finalize()
                        break;
                    }
                    //check if a commit command should be executed

                    bool r = do_commit(last_commit, commit_counter, trans, uncommited);
                    if(!r) {
                        break;
                    }

                    if(wait_res == false) {//there is no new object to store
                        continue;
                    }

                    auto nw = std::chrono::high_resolution_clock::now();
                    auto time_to_last_shrink = std::chrono::duration_cast<std::chrono::seconds>(nw - last_shrink).count();
                    //poping an object from the Q
                    {
                        std::lock_guard<std::mutex> m{_que_gurad};
                        p = _que.front();
                        p2 = *p;
                        _que.pop_front();
                        //shrink the q to release memory
                        if(time_to_last_shrink >= _init_param.commit_timeout) {
                            _que.shrink_to_fit();
                            last_shrink = std::chrono::high_resolution_clock::now();
                        }
                    }

                    uncommited.push_back(p);
                    try {
                        do_persist(p);
                        p2 = *p;
                        ++commit_counter;
                    } catch(const odb::exception &e) {
                        //do reconnection

                        bool r = reconnect(trans);
                        if(!r) {
                            break;
                        }
                        try {
                            do_persist(p);
                            p2 = *p;
                            ++commit_counter;
                        } catch(const odb::exception &e) {
                            persisted = false;
                            tidm::exception ox("odb", "exception" , e.what());
                            ox.add_msg(__FILE__, __FUNCTION__, " unable to persist type: % after the connection recovery",
                                       typeid(T).name());
                            if(_local_exception_handler && p != nullptr) {
                                _local_exception_handler(ox, *p);
                            } else {
                                _exception_handler(ox);
                            }
                            //remove the currect object because its persisting throws exception even after reconnection
                            if(p != nullptr) {
                                delete p;
                            }
                            p = nullptr;
                            if(uncommited.size() > 0) {
                                uncommited.pop_back();
                            }

                            {
                                std::lock_guard<std::mutex> m{_stat_gurad};
                                _stat.update(0, execution_state::FAILED);
                            }
                        }
                        {
                            std::lock_guard<std::mutex> m{_que_gurad};
                            for(const auto &i : uncommited) {
                                _que.push_back(i);
                                _sem.notify();
                            }
                            uncommited.clear();
                        }
                    }

                    r = do_commit(last_commit, commit_counter, trans, uncommited);
                    if(!r) {
                        break;
                    }
                    if(_post_handler && persisted) {
                        try {
                            _post_handler(p2);
                        } catch(...) {
                        }
                    }
                }
                try {
                    trans->commit();
                } catch(const odb::exception &ex) {
                    tidm::exception ox(__FILE__, __FUNCTION__, "odb exception on type `%': %" , typeid(T).name(), ex.what());
                    if(_local_exception_handler && p != nullptr) {
                        _local_exception_handler(ox, *p);
                    } else {
                        _exception_handler(ox);
                    }
                }
            } catch(std::exception &ex) {
                tidm::exception ox(__FILE__, __FUNCTION__, "worker thread on type % terminated due to std::exception: %",
                                   typeid(T).name(), ex.what());
                if(_local_exception_handler && p != nullptr) {
                    _local_exception_handler(ox, *p);
                } else {
                    _exception_handler(ox);
                }
            } catch(...) {
                tidm::exception ox(__FILE__, __FUNCTION__, "worker thread on type % terminated due to an unknown exception",
                                   typeid(T).name());
                if(_local_exception_handler && p != nullptr) {
                    _local_exception_handler(ox, *p);
                } else {
                    _exception_handler(ox);
                }
            }
        }

    public:

};
}

#endif
