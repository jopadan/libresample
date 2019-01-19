#!/bin/sh
aclocal -I config --force --install
libtoolize --force --copy
autoheader
automake --add-missing --copy
autoconf
autoreconf -ivf
