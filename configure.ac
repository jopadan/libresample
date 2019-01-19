dnl
dnl libresample configure.in script
dnl
dnl Dominic Mazzoni
dnl

# Release version
m4_define([package_version_major],[0])
m4_define([package_version_minor],[1])
m4_define([package_version_micro],[4])
 
# API version
m4_define([api_version],[1])

AC_INIT([libresample],[package_version_major.package_version_minor.package_version_micro], [Dominic Mazzoni dominic@minorninth.com], [http://github.com/minorninth/libresample])

dnl Require autoconf >= 2.13
AC_PREREQ(2.13)
LT_PREREQ([2.2])

dnl Dependencies
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

dnl version variables
AC_SUBST([PACKAGE_VERSION_MAJOR],package_version_major)
AC_SUBST([PACKAGE_VERSION_MINOR],package_version_minor)
AC_SUBST([PACKAGE_VERSION_MICRO],package_version_micro)
AC_SUBST([API_VERSION],api_version)
AC_SUBST([PACKAGE_VERSION],[package_version_major,
                            package_version_minor,
			    package_version_micro])
AC_SUBST(TARGETS)
TARGETS="libsamplerate.la tests/testresample"

dnl 
AM_EXTRA_RECURSIVE_TARGETS([tests])
AC_CONFIG_MACRO_DIRS([m4])
AM_INIT_AUTOMAKE([subdir-objects])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PATH_PROG([PKG_CONFIG], [pkg-config])
LT_INIT([dlopen])

dnl output files
AC_CONFIG_FILES([Makefile] [pkgconfig/libresample.pc:pkgconfig/libresample.pc.in])
 

dnl enable test dependencies
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

dnl casual header checks
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_HEADERS([sys/time.h])
AC_CHECK_HEADERS(inttypes.h)
AC_CONFIG_HEADER(src/config.h:src/configtemplate.h)

dnl check for required funcs
AC_CHECK_FUNCS([floor])
AC_CHECK_FUNCS([gettimeofday])
AC_CHECK_FUNCS([memset]) 
AC_CHECK_FUNCS([sqrt])
AC_CHECK_FUNCS([strstr])

dnl output files and finish configure
AC_OUTPUT

echo ""

if [[ $have_libsamplerate = "yes" ]] ; then
	echo "Configured to build tests/resample-sndfile using libsndfile"
	echo ""
else if [[ x$test_arg = x"yes" ]] ; then
	echo "Could not find libsndfile - needed if you want to"
	echo "compile tests/resample-sndfile"
	echo ""
	fi
fi

if [[ $have_libsamplerate = "yes" ]] ; then
	echo "Configured to build tests/compareresample to compare against"
   echo "Erik de Castro Lopo's libsamplerate library."
	echo ""
else if [[ x$test_arg = x"yes" ]] ; then
	echo "Could not find libsamplerate - only needed if you want to"
	echo "compile tests/compareresample to compare their performance."
	echo ""
	fi
fi

echo "Type 'configure --help' to see options."
echo ""
echo "Type 'make' to build libresample."
