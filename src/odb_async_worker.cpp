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

#include "odb_async_worker.hpp"

tidm::odb_async_worker::odb_async_worker()
{
    _state = odb_worker_base::state::NEW;
    _db = nullptr;
}

void tidm::odb_async_worker::init(odb::database *db,
                                  const odb_worker_param &prm,
                                  std::function<void(tidm::exception)>  handler)

{

    if(_state != odb_worker_base::state::NEW) {
        throw tidm::exception(__FILE__, __FUNCTION__,
                              "invalid state(re-initialization or initialization of a finalized worker)");
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
    _state = odb_worker_base::state::READY;
}

tidm::odb_stat tidm::odb_async_worker::get_stat()throw()
{

    std::map<std::string, odb_worker_base *>::iterator it;
    odb_stat st, aggr_st;
    if(_state == odb_worker_base::state::READY) {
        {
            std::lock_guard<std::mutex> m(_workers_guard);
            for(it = _workers.begin(); it != _workers.end(); it++) {
                st = it->second->get_stat();
                aggr_st = aggr_st + st;
            }
        }
    }
    return aggr_st;
}

void tidm::odb_async_worker::finalize()throw()
{

    if(_state == odb_worker_base::state::READY) {
        std::map<std::string, odb_worker_base *>::iterator it;
        {
            std::lock_guard<std::mutex> m(_workers_guard);
            for(it = _workers.begin(); it != _workers.end(); it++) {
                it->second->finalize();
                delete it->second;
            }
        }
    }
    _state = odb_worker_base::state::TERMINATED;
}

