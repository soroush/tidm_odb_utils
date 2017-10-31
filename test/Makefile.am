ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
AM_CFLAGS = --pedantic
AM_CXXFLAGS = --pedantic
AM_CPPFLAGS = -I../src/ -Wall -Werror -Wno-unknown-pragmas\
    $(OI_EXCEPTION_CFLAGS) \
	$(OI_COMMON_CFLAGS) \
	$(ODB_CFLAGS) \
	$(ODB_ORACLE_CFLAGS) \
	$(BOOST_SYSTEM_CFLAGS)


LDADD=../src/.libs/liboi_odb_utils.a \
	$(ODB_LIBS) \
	$(ODB_ORACLE_LIBS) \
	$(OI_COMMON_LIBS) \
	$(OI_EXCEPTION_LIBS) \
	$(BOOST_SYSTEM_LIBS)

check_PROGRAMS = test_post_callback test_odb_worker
test_odb_worker_SOURCES = main.cpp req_agent_odb.cpp 
test_post_callback_SOURCES= test_post_handler.cpp student-odb.cxx
#TESTS = $(check_PROGRAMS)
TESTS = test_post_callback

