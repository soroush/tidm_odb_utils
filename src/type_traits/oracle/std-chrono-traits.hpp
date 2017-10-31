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

#ifndef TIDM_ODB_ORACLE_TRAITS_STD_CHRONO_HPP
#define TIDM_ODB_ORACLE_TRAITS_STD_CHRONO_HPP

#include <odb/oracle/traits.hxx>
#include <odb/oracle/details/date.hxx>
#include <odb/details/buffer.hxx>

#include <chrono>
#include <ctime>
#include <iostream>

namespace odb {
namespace oracle {

template <>
class value_traits<std::chrono::system_clock::time_point, id_date> {
    public:
        typedef std::chrono::system_clock::time_point value_type;
        typedef value_type query_type;
        typedef char image_type;

        static void
        set_value (value_type& v,
                   const char b[7],
                   bool is_null) {
            tm time;
            std::time_t time_info;
            if(!is_null) {
                short year;
                unsigned char month;
                unsigned char day;
                unsigned char hour;
                unsigned char minute;
                unsigned char second;
                details::get_date(b,
                                  year,
                                  month,
                                  day,
                                  hour,
                                  minute,
                                  second);
                time.tm_year = static_cast<int>(year-1900);
                time.tm_mon = static_cast<int>(month-1);
                time.tm_mday = static_cast<int>(day);
                time.tm_hour= static_cast<int>(hour);
                time.tm_min= static_cast<int>(minute);
                time.tm_sec= static_cast<int>(second);
                time_info = timegm(&time);
            }
            else {
                time_info = 0;
            }
            v = std::chrono::system_clock::from_time_t(time_info);
        }

        static void
        set_image (char b[7],
                   bool& is_null,
                   const value_type& v) {
            std::time_t time_info;
            tm* time;
            if(!is_null) {
                time_info = std::chrono::system_clock::to_time_t(v);
                time = gmtime(&time_info);
            }
            else {
                time = 0;
            }
            short year = static_cast<short>(time->tm_year);
            unsigned char month = static_cast<unsigned char>(time->tm_mon);
            unsigned char day = static_cast<unsigned char>(time->tm_mday);
            unsigned char hour = static_cast<unsigned char>(time->tm_hour);
            unsigned char minute = static_cast<unsigned char>(time->tm_min);
            unsigned char second = static_cast<unsigned char>(time->tm_sec);
            details::set_date(b,
                              year+1900,
                              month+1,
                              day,
                              hour,
                              minute,
                              second);
            //delete time;
        }
};
}
}
#endif
