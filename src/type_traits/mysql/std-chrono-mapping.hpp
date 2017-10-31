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

#ifndef TIDM_ODB_MYSQL_STD_CHRONO_MAPPING
#define TIDM_ODB_MYSQL_STD_CHRONO_MAPPING

#include <chrono>

// By default map std::chrono::system_clock::time_point to MySQL TIMESTAMP. We use
// the NULL value to represent 1970-01-01.
//
#pragma db value(std::chrono::system_clock::time_point) type("TIMESTAMP") null

#endif // TIDM_ODB_MYSQL_STD_CHRONO_MAPPING
