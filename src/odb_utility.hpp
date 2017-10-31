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

#ifndef TIDM_ODB_UTILITY_HPP
#define TIDM_ODB_UTILITY_HPP

#include <odb/database.hxx>
#include <odb/result.hxx>
#include <odb/query.hxx>
#include <odb/transaction.hxx>
#include <odb/exception.hxx>
#include <functional>
#include <exception.hpp>
#include <vector>
#include <list>

namespace tidm {
class odb_travers {
    public :
        template <typename T>
        static void travers(odb::database *_db , std::function<void(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    func(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers(odb::database *_db , odb::query<T> query , std::function<void(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    func(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }


        template <typename T>
        static void travers(odb::database *_db , odb::query<T> &query , std::function<void(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    func(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        //-----------------------------------------------------------------------------------------------------------
        template <typename T>
        static void travers(odb::database *_db , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers(odb::database *_db , odb::query<T> query , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }


        template <typename T>
        static void travers(odb::database *_db , odb::query<T> &query , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        //------------------------------------------------------------------------------
        template <typename T>
        static void travers_ex(odb::database *_db , std::function<void(T &)> func) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    func(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers_ex(odb::database *_db ,  odb::query<T> &query , std::function<void(T &)> func) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    func(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers_ex(odb::database *_db , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers_ex(odb::database *_db ,  odb::query<T> query , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }


        template <typename T>
        static void travers_ex(odb::database *_db , odb::query<T> &query , std::function<bool(T &)> func) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    if(func(p) == false) {
                        break;
                    }
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        //--------------------------------------------------------------------------------
        template <typename T>
        static void travers(odb::database *_db , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {

                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers(odb::database *_db , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {

                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers(odb::database *_db , odb::query<T> query , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers(odb::database *_db , odb::query<T> query , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers(odb::database *_db , odb::query<T> &query , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers(odb::database *_db , odb::query<T> &query , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            if(_db == NULL) {
                tidm::exception ox(__FILE__, __FUNCTION__, "the db is null");
                throw ox;
            }
            try {
                odb::transaction t(_db->begin());
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
                t.commit();
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        //-------------------------------------------------------------------------------------------

        template <typename T>
        static void travers_ex(odb::database *_db , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            i_vec.clear();
            try {
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers_ex(odb::database *_db , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>());
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers_ex(odb::database *_db , odb::query<T> query , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

        template <typename T>
        static void travers_ex(odb::database *_db , odb::query<T> query , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers_ex(odb::database *_db , odb::query<T> &query , std::vector<T> &i_vec) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_vec.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }
        template <typename T>
        static void travers_ex(odb::database *_db  , odb::query<T> &query , std::list<T> &i_list) {
            typedef odb::result<T> def_result;
            try {
                def_result def_list_result(_db->query<T>(query));
                for(T &p : def_list_result) {
                    i_list.push_back(p);
                }
            } catch(odb::exception &dx) {
                tidm::exception ox("std", "exception", dx.what());
                ox.add_msg(__FILE__, __FUNCTION__, "unable to travers table");
                throw ox;
            }
        }

};
}

#endif // ODB_UTILITY_HPP

