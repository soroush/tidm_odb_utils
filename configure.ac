AC_PREREQ([2.67])
AC_INIT([tidm_odb_utils], [7.0], [oi@tidm.ir])
LT_INIT
LT_LANG([C++])
AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])

AM_INIT_AUTOMAKE
AM_SILENT_RULES([yes])
AC_PROG_LIBTOOL
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AX_PKG_CHECK_MODULES([ODB], [libodb >= 2.4])

dnl AX_PKG_CHECK_MODULES([ODB_ORACLE], [], [libodb-oracle >= 2.4],
dnl                      [AC_DEFINE([HAVE_ODB_ORACLE], [1], [ODB Oracle Connector is available.])],
dnl                      [AC_MSG_WARN([ODB Oracle Connector library is not installed. Oracle type traits will not be installed.])
dnl ])

AX_PKG_CHECK_MODULES([ODB_MYSQL], [], [libodb-mysql >= 2.4],
                     [AC_DEFINE([HAVE_ODB_MYSQL], [1], [ODB MySQL Connector is available.])],
                     [AC_MSG_WARN([ODB MySQL Connector library is not installed. MySQL type traits will not be installed.])
])

AX_PKG_CHECK_MODULES([TIDM_COMMON], [tidm_common >= 7.1])
AX_PKG_CHECK_MODULES([TIDM_EXCEPTION], [tidm_exception >= 7.0])

AC_CONFIG_FILES([Makefile
                src/Makefile
                test/Makefile
                tidm_odb_utils.pc])

AC_SUBST([TIDM_ODB_UTILS_SO_VERSION], [7:0:0])
AC_SUBST([TIDM_ODB_UTILS_API_VERSION], [7.0.0])

AC_OUTPUT
