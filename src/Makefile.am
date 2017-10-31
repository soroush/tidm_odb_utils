ACLCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

AM_CPPFLAGS = \
	$(ODB_CFLAGS) \
	$(ODB_ORACLE_CFLAGS) \
	$(ODB_MYSQL_CFLAGS) \
	$(TIDM_COMMON_CFLAGS) \
	$(TIDM_EXCEPTION_CFLAGS)

AM_CXXFLAGS = \
	--pedantic -Wall -Werror -Wno-unknown-pragmas -Wno-deprecated-declarations

lib_LTLIBRARIES = libtidm_odb_utils.la

libtidm_odb_utils_la_SOURCES = \
    type_traits/std_chrono.hpp \
	type_traits/std_chrono_oracle.hpp \
	odb_stat.cpp \
	odb_worker.cpp \
	odb_async_worker.cpp

libtidm_odb_utils_la_LDFLAGS = -version-info $(TIDM_ODB_UTILS_SO_VERSION)

libtidm_odb_utils_la_LIBADD = \
	$(ODB_LIBS) \
	$(ODB_ORACLE_LIBS) \
	$(ODB_MYSQL_LIBS) \
	$(TIDM_COMMON_LIBS) \
	$(TIDM_EXCEPTION_LIBS)

tidm_odb_utils_includedir = $(includedir)/tidm/utils/odb_utils/
nobase_tidm_odb_utils_include_HEADERS = \
	odb_stat.hpp \
	odb_worker.hpp \
	odb_async_worker.hpp \
	odb_utility.hpp \
    type_traits/oracle/std-chrono-traits.hpp \
	type_traits/oracle/std-chrono-mapping.hpp \
	type_traits/mysql/std-chrono-traits.hpp \
	type_traits/mysql/std-chrono-mapping.hpp
