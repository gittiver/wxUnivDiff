#!/bin/sh

HOST_SYSTEM=`uname -s`
HOST_ARCH=`uname -m`
STARTDIR=`pwd`

CMAKE_BUILDDIR=build/$HOST_ARCH-$HOST_SYSTEM
WXDIR=$STARTDIR/../wxWidgets/3.0.0

mkdir -p $CMAKE_BUILDDIR

cd $CMAKE_BUILDDIR

cmake -DwxUnivDiff_WITH_DOCS:bool=ON \
	  -DwxUnivDiff_WITH_TESTS:bool=ON \
      -DCXXTEST_INCLUDE_DIR=3rdparty/cxxtest \
      -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=3rdparty/cxxtest/bin/cxxtestgen \
      -DwxWidgets_CONFIG_EXECUTABLE:FILEPATH=$WXDIR/build-cocoa-debug/wx-config \
      ../..

cmake --build . --target all --target test --target package 
cmake --build . --target package_source
cd $STARTDIR

mkdir -p build/Xcode
cd build/Xcode
cmake -DwxUnivDiff_WITH_DOCS:bool=ON \
	  -DwxUnivDiff_WITH_TESTS:bool=ON \
      -DCXXTEST_INCLUDE_DIR=3rdparty/cxxtest \
      -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=3rdparty/cxxtest/bin/cxxtestgen \
      -DwxWidgets_CONFIG_EXECUTABLE:FILEPATH=$WXDIR/build-cocoa-debug/wx-config \
      -G Xcode ../..
cd $STARTDIR

