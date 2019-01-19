dnl
dnl libresample configure.in script
dnl
dnl Dominic Mazzoni
dnl

# Release version
m4_define([package_version_major],[0])
m4_define([package_version_minor],[1])
m4_define([package_version_micro],[3])
 
# API version
m4_define([api_version],[1])

AC_INIT([libresample],[package_version_major.package_version_minor.package_version_micro], [Dominic Mazzoni dominic@minorninth.com], [http://github.com/minorninth/libresample])
dnl Require autoconf >= 2.13
AC_PREREQ(2.13)
LT_PREREQ([2.2])
# Dependencies
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

AC_SUBST([PACKAGE_VERSION_MAJOR],package_version_major)
AC_SUBST([PACKAGE_VERSION_MINOR],package_version_minor)
AC_SUBST([PACKAGE_VERSION_MICRO],package_version_micro)
AC_SUBST([API_VERSION],api_version)

AM_EXTRA_RECURSIVE_TARGETS([tests])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([subdir-objects])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PATH_PROG([PKG_CONFIG], [pkg-config])
LT_INIT([dlopen])
AC_SUBST(TARGETS)
TARGETS="libsamplerate.la tests/testresample"

AC_CONFIG_FILES([Makefile] [pkgconfig/libresample.pc:pkgconfig/libresample.pc.in])
 
 
 
AC_ARG_ENABLE(test, AC_HELP_STRING([--enable-test], [enable tests using libsndfile and libsamplerate]), test_arg="yes", test_arg="no")

if [[ x$test_arg = "xyes" ]] ; then
	AC_CHECK_LIB(sndfile, sf_open, have_libsndfile=yes, have_libsndfile=no)
	AC_CHECK_HEADER(sndfile.h, , have_libsndfile=no)

	if [[ $have_libsndfile = "yes" ]] ; then
		TARGETS="$TARGETS tests/resample-sndfile"
	fi
	
	AC_CHECK_LIB(samplerate, src_simple, have_libsamplerate=yes, have_libsamplerate=no)
	AC_CHECK_HEADER(samplerate.h, , have_libsamplerate=no)

	if [[ $have_libsamplerate = "yes" ]] ; then
		TARGETS="$TARGETS tests/compareresample"
	fi
else
	have_libsamplerate="no"
	have_libsndfile="no"
fi

AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_FUNCS([floor])
AC_CHECK_FUNCS([gettimeofday])
AC_CHECK_FUNCS([memset]) 
AC_CHECK_FUNCS([sqrt])
AC_CHECK_FUNCS([strstr])
AC_CHECK_HEADERS([sys/time.h])

AC_CHECK_HEADERS(inttypes.h)
AC_CONFIG_HEADER(src/config.h:src/configtemplate.h)
AC_OUTPUT
