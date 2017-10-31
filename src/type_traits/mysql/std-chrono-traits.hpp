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

#ifndef TIDM_ODB_MYSQL_STD_CHRONO_TRAITS_HPP
#define TIDM_ODB_MYSQL_STD_CHRONO_TRAITS_HPP

#include <odb/pre.hxx>
#include <odb/core.hxx>
#include <odb/mysql/traits.hxx>
#include <chrono>

namespace odb {
namespace mysql {
template <>
struct default_value_traits<::std::chrono::system_clock::time_point, id_datetime> {
    typedef ::std::chrono::system_clock::time_point value_type;
    typedef ::std::chrono::system_clock::time_point query_type;
    typedef ::std::chrono::microseconds time_duration;
    typedef MYSQL_TIME image_type;

    static void
    set_value(value_type &v, const image_type &i, bool is_null) {
        if(is_null)
            v = value_type{};
        else {
            // Since MySQL 5.6.4, the microseconds part is no longer ignored.
            // We will assume UTC time
            std::tm timeinfo = std::tm();
            timeinfo.tm_year = i.year - 1900; // year since 1900 ex. 100 = 2000
            timeinfo.tm_mon = i.month - 1;
            timeinfo.tm_mday = i.day;
            timeinfo.tm_hour = i.hour;
            timeinfo.tm_min = i.minute;
            timeinfo.tm_sec = i.second;
            std::time_t tt = std::mktime(&timeinfo);
            v = std::chrono::system_clock::from_time_t(tt)
                + time_duration(i.second_part);
        }
    }

    static void
    set_image(image_type &i, bool &is_null, const value_type &v) {
        const std::time_t tt = std::chrono::system_clock::to_time_t(v);
        const std::tm *tm = std::gmtime(&tt);
        is_null = false;
        i.neg = false;
        i.year = tm->tm_year + 1900;
        i.month = tm->tm_mon + 1; // But why?
        i.day = tm->tm_mday;
        i.hour = tm->tm_hour;
        i.minute = tm->tm_min;
        i.second = tm->tm_sec;
        time_duration d = std::chrono::duration_cast<time_duration>(v.time_since_epoch());
        i.second_part = d.count() % 1000000UL;
    }
};

template <>
struct default_value_traits<::std::chrono::system_clock::time_point, id_timestamp> {
    typedef ::std::chrono::system_clock::time_point value_type;
    typedef ::std::chrono::system_clock::time_point query_type;
    typedef ::std::chrono::microseconds time_duration;
    typedef MYSQL_TIME image_type;

    static void
    set_value(value_type &v, const image_type &i, bool is_null) {
        if(is_null)
            v = value_type{};
        else {
            // Since MySQL 5.6.4, the microseconds part is no longer ignored.
            // MySQL TIMESTAMP type is always UTC
            std::tm timeinfo = std::tm();
            timeinfo.tm_year = i.year - 1900; // year since 1900 ex. 100 = 2000
            timeinfo.tm_mon = i.month - 1;
            timeinfo.tm_mday = i.day;
            timeinfo.tm_hour = i.hour;
            timeinfo.tm_min = i.minute;
            timeinfo.tm_sec = i.second;
            std::time_t tt = std::mktime(&timeinfo);
            v = std::chrono::system_clock::from_time_t(tt)
                + time_duration(i.second_part);
        }
    }

    static void
    set_image(image_type &i, bool &is_null, const value_type &v) {
        const std::time_t tt = std::chrono::system_clock::to_time_t(v);
        const std::tm *tm = std::gmtime(&tt);
        is_null = false;
        i.neg = false;
        i.year = tm->tm_year + 1900;
        i.month = tm->tm_mon + 1;
        i.day = tm->tm_mday;
        i.hour = tm->tm_hour;
        i.minute = tm->tm_min;
        i.second = tm->tm_sec;
        time_duration d = std::chrono::duration_cast<time_duration>(v.time_since_epoch());
        i.second_part = d.count() % 1000000UL;
    }
};

template <>
struct default_type_traits<::std::chrono::system_clock::time_point> {
    static const database_type_id db_type_id = id_timestamp;
};

}
}

#include <odb/post.hxx>

#endif // ODB_BOOST_DATE_TIME_MYSQL_POSIX_TIME_TRAITS_HXX
