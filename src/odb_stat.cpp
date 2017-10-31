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

#include "odb_stat.hpp"

namespace tidm {
std::ostream &operator<<(std::ostream &os, const odb_stat &od)
{
    os << " fail: " << od._failure_count
       << " recover attempts: " << od._recover_count
       << " que len: " << od._que_len
       << " success: {";
    os << static_cast<stat_info>(od);
    os << "}(us)";
    return os;
}
}

tidm::odb_stat::odb_stat(): stat_info()
{
    _que_len    = 0;
    _failure_count = 0;
    _recover_count = 0;
    _is_active = false;
}

tidm::odb_stat::odb_stat(const stat_info &st): stat_info(st)
{
    _que_len    = 0;
    _failure_count = 0;
    _recover_count = 0;
    _is_active = false;
}

tidm::odb_stat tidm::odb_stat::operator+(const odb_stat &od)
{
    odb_stat os(stat_info::operator+(static_cast<stat_info>(od)));
    os._que_len = _que_len + od._que_len;
    os._failure_count = _failure_count  + od._failure_count ;
    os._recover_count = _recover_count  + od._recover_count ;
    return os;
}

int  tidm::odb_stat::get_que_len()const
{
    return _que_len;
}

int  tidm::odb_stat::get_fail_count() const
{
    return _failure_count;
}

int  tidm::odb_stat::get_recover_count() const
{
    return _recover_count;
}

void tidm::odb_stat::set_que_len(size_t len)
{
    _que_len = static_cast<int>(len);
}

void tidm::odb_stat::update(uint64_t val, execution_state st)
{
    if(_is_active) {
        switch(st) {
        case execution_state::SUCCESS:
            set(val);
            break;
        case execution_state::RECOVERING:
            _recover_count++;
            break;
        case execution_state::FAILED:
            _failure_count++;
            break;
        };
    }
}

void tidm::odb_stat::reset()
{
    _is_active = true;
    _que_len = 0;
    _failure_count = 0;
    _recover_count = 0;
    stat_info::reset();
}
