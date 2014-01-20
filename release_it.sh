#!/bin/sh

HOST_SYSTEM=`uname -s`
HOST_ARCH=`uname -m`

AM_BUILDDIR=build/autotools/$HOST_ARCH-$HOST_SYSTEM
CMAKE_BUILDDIR=build/cmake/$HOST_ARCH-$HOST_SYSTEM
STARTDIR=`pwd`

mkdir -p $CMAKE_BUILDDIR

cd $CMAKE_BUILDDIR
#rm CMakeCache.txt
cmake -D WITH_DOCS:bool=ON -D wxUnivDiff_WITH_TESTS:bool=ON $STARTDIR
cmake --build --target all --target test --target package --target package_source
cd $STARTDIR

#mkdir -p $AM_BUILDDIR
#cd $AM_BUILDDIR
#$STARTDIR/configure 
#make distcheck
#cd $STARTDIR
