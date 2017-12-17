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

#ifndef TIDM_ODB_ASYNC_WORKER_HPP
#define TIDM_ODB_ASYNC_WORKER_HPP

#include "odb_worker.hpp"

namespace tidm {
class odb_async_worker {
    public:
        odb_async_worker();
        void init(odb::database *db, const odb_worker_param &prm, std::function<void(tidm::exception)>  handler);
        odb_stat get_stat()throw();

        template<typename T>
        void set_local_handler(std::function<void(tidm::exception, const T &obj)>  handler, std::function<void(const T &obj)> post_callback = nullptr) {
            if(_state != odb_worker_base::state::READY) {
                throw tidm::exception(__FILE__, __FUNCTION__, "invalid use of un-initilized/finalized worker");
            }
            std::string t_name = typeid(T).name();
            std::map<std::string, odb_worker_base *>::iterator it;
            odb_worker<T> *wr = nullptr;
            {
                std::lock_guard<std::mutex> m(_workers_guard);
                it = _workers.find(t_name);
                if(it == _workers.end()) {
                    wr = new odb_worker<T>();
                    wr->init(_db, _init_param, handler, _exception_handler, post_callback);
                    _workers[t_name] = static_cast<odb_worker_base *>(wr);
                } else {
                    throw tidm::exception(__FILE__, __FUNCTION__, "unable to recreate channel! this method should be called before any `persist' invokation");
                }
            }


        }
        template<typename T>
        void persist(const T &obj) {

            if(_state != odb_worker_base::state::READY) {
                throw tidm::exception(__FILE__, __FUNCTION__, "invalid use of un-initilized/finalized worker");
            }
            std::string t_name = typeid(T).name();
            std::map<std::string, odb_worker_base *>::iterator it;
            odb_worker<T> *wr = nullptr;
            {
                std::lock_guard<std::mutex> m(_workers_guard);

                it = _workers.find(t_name);
                if(it == _workers.end()) {
                    wr = new odb_worker<T>();
                    wr->init(_db, _init_param, _exception_handler);
                    _workers[t_name] = static_cast<odb_worker_base *>(wr);
                } else {
                    wr = static_cast<odb_worker<T>*>(it->second);
                }
            }
            wr->persist(obj);
        }

        void finalize()throw();
    private:
        odb_worker_base::state _state;
        std::map<std::string, odb_worker_base *> _workers;
        std::mutex _workers_guard;
        odb_worker_param _init_param;
        odb::database *_db;
        std::function<void(tidm::exception)> _exception_handler;

        odb_async_worker(const odb_async_worker &); //is PRIVATE to avoid pass by value - no body_base
        odb_async_worker &operator=(const odb_async_worker &); //is PRIVATE to avoid assigning - no body

};
}
#endif

