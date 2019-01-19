DISTCHECK_CONFIGURE_FLAGS = --enable-test

ACLOCAL_AMFLAGS = -I m4 --install

EXTRA_DIST = README.md LICENSE-BSD.txt LICENSE-LGPL.txt
pkgconfig_DATA = pkgconfig/libresample.pc

lib_LTLIBRARIES = libresample.la

include_HEADERS = include/libresample.h
noinst_HEADERS = src/resample_defs.h \
src/filterkit.h \
src/config.h 

libresample_la_LIBADD = ${LIBOBJS} -lm

libresample_la_SOURCES = include/libresample.h \
src/resample_defs.h \
src/resample.c \
src/resamplesubs.c \
src/filterkit.h \
src/filterkit.c \
src/config.h

libresample_BUILT_TESTS = testresample compareresample resample-sndfile
bin_PROGRAMS = $(libresample_BUILT_TESTS)
TESTS = testresample compareresample 
check_PROGRAMS = $(TESTS)

testresample_LDADD = -lresample ${LIBS} -lm
testresample_SOURCES = tests/testresample.c
testresample_DEPENDENCIES = libresample.la

compareresample_LDADD = -lsamplerate \
                        -lresample \
			${LIBS} -lm

compareresample_SOURCES = tests/compareresample.c 
compareresample_DEPENDENCIES = libresample.la

resample_sndfile_LDADD = -lsndfile -lresample ${LIBS} -lm 
resample_sndfile_SOURCES = tests/resample-sndfile.c
resample_sndfile_DEPENDENCIES = libresample.la


