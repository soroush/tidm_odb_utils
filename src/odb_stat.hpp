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

#ifndef TIDM_ODB_STAT_HPP
#define TIDM_ODB_STAT_HPP

#include <tidm/utils/common/stat_info.hpp>
#include <iostream>

namespace tidm {
enum class execution_state {SUCCESS = 0, RECOVERING = 1, FAILED = 2 };
class odb_stat: public stat_info {
        friend std::ostream &operator<<(std::ostream &os, const odb_stat &od);
    public:
        odb_stat();
        odb_stat(const stat_info &);
        odb_stat operator+(const odb_stat &od);
        void reset();
        void set_que_len(size_t len);
        void update(uint64_t val, execution_state st);
        int get_que_len()const;
        int get_fail_count()const;
        int get_recover_count()const;
    private:
        bool _is_active;
        int _que_len;
        int _failure_count;
        int _recover_count;
};

std::ostream &operator<<(std::ostream &os, const odb_stat &od);
}

#endif
