#!/bin/sh

HOST_SYSTEM=`uname -s`
HOST_ARCH=`uname -m`
STARTDIR=`pwd`

CMAKE_BUILDDIR=build/$HOST_ARCH-$HOST_SYSTEM

mkdir -p $CMAKE_BUILDDIR

cd $CMAKE_BUILDDIR

if [ "$HOST_SYSTEM" = "Linux" ] 
then 
cmake -DwxUnivDiff_WITH_DOCS:bool=ON \
	  -DwxUnivDiff_WITH_TESTS:bool=ON \
      -DCXXTEST_INCLUDE_DIR=3rdparty/cxxtest \
      -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=3rdparty/cxxtest/bin/cxxtestgen \
      ../..

cmake --build . --target all --target test --target package 
cmake --build . --target package_source
cd $STARTDIR

else 

WXDIR=$STARTDIR/../wxWidgets/3.2.2.1

cmake -DwxUnivDiff_WITH_DOCS:bool=ON \
	  -DwxUnivDiff_WITH_TESTS:bool=ON \
      -DCXXTEST_INCLUDE_DIR=$STARTDIR/3rdparty/cxxtest \
      -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=$STARTDIR/3rdparty/cxxtest/bin/cxxtestgen \
      -DwxWidgets_CONFIG_EXECUTABLE:FILEPATH=$WXDIR/build-debug/wx-config \
      ../..

cmake --build . --target all
cmake --build . --target test
cmake --build . --target package 
cmake --build . --target package_source
cd $STARTDIR

mkdir -p build/Xcode
cd build/Xcode
cmake -DwxUnivDiff_WITH_DOCS:bool=ON \
	  -DwxUnivDiff_WITH_TESTS:bool=ON \
      -DCXXTEST_INCLUDE_DIR=3rdparty/cxxtest \
      -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=3rdparty/cxxtest/bin/cxxtestgen \
      -DwxWidgets_CONFIG_EXECUTABLE:FILEPATH=$WXDIR/build-debug/wx-config \
      -G Xcode ../..
cd $STARTDIR

fi

