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

#include "odb_worker.hpp"

namespace tidm {

odb_worker_param::odb_worker_param()
{
    max_que_size = 0;
    pool_size = 0;
    commit_timeout = 0;
    commit_count = 0;
}
std::string odb_worker_param::to_string()const
{
    std::stringstream sstr;
    sstr << "max_que_size: " << max_que_size
         << "pool_size: " << pool_size
         << "commit_count: " << commit_count
         << "commit_timeout: " << commit_timeout;
    return sstr.str();
}

odb_worker_base::odb_worker_base()
{
    _state = state::NEW;
    _db = nullptr;
}

void odb_worker_base::init(odb::database *db,
                           const odb_worker_param &prm,
                           std::function<void(tidm::exception)>  handler) throw(tidm::exception)
{
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
    _exception_handler  = handler;
    _init_param = prm;
    _db = db;
    _state = state::READY;
    for(int i = 0; i < _init_param.pool_size; i++) {
        _worker_threads.emplace_back(&odb_worker_base::worker, this);
    }
}
odb_stat odb_worker_base::get_stat()throw()
{
    odb_stat temp;
    {
        std::lock_guard<std::mutex> m(_stat_gurad);
        temp = _stat;
        _stat.reset();
    }
    return temp;
}



void odb_worker_base::finalize()throw()
{
    if(_state == state::READY) {
        _state = state::TERMINATED;
        for(auto &th : _worker_threads) {
            th.join();
        }
    }
    _state = state::TERMINATED;
}

}
