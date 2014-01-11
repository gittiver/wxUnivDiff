set WXDIR=../wxWidgets/2.9.5

set PATH=%PATH%;C:\Program Files (x86)\CMake 2.8\bin

set CMAKE_BUILDDIR=build\vc
set STARTDIR=%CD%


@if NOT "%VS100COMNTOOLS%"=="" (call "%VS100COMNTOOLS%\vsvars32.bat" & goto VS_END)
@if NOT "%VS90COMNTOOLS%"=="" (call "%VS90COMNTOOLS%\vsvars32.bat" & goto VS_END)
@if NOT "%VS80COMNTOOLS%"=="" (call "%VS80COMNTOOLS%\vsvars32.bat" & goto VS_END)
@if NOT "%VS71COMNTOOLS%"=="" (call "%VS71COMNTOOLS%\vsvars32.bat" & goto VS_END)

:VS_END

cd %STARTDIR%

set CMAKE_BUILDDIR=build\vc
mkdir %CMAKE_BUILDDIR%

cd %CMAKE_BUILDDIR%

del CMakeCache.txt

cmake %STARTDIR% -DCXXTEST_INCLUDE_DIR=%STARTDIR%\..\..\..\cxxtest -DCXXTEST_PYTHON_TESTGEN_EXECUTABLE=%STARTDIR%\..\..\..\cxxtest\bin\cxxtestgen -DWITH_TESTS:bool=ON -D LITESQL_MSVC_MT:BOOL=OFF -D wxWidgets_ROOT_DIR:FILEPATH=%WXDIR% -D wxWidgets_LIB_DIR:FILEPATH=%WXDIR%\lib\vc_lib %STARTDIR%

pause

devenv cmi.sln /Rebuild Debug /Project ALL_BUILD /ProjectConfig Debug
devenv /Rebuild Release cmi.sln /Project ALL_BUILD /ProjectConfig Debug

devenv /Build Debug cmi.sln /Project RUN_TESTS /ProjectConfig Debug

devenv /Build Release cmi.sln /Project PACKAGE /ProjectConfig Release

rem cpack --config CPackSourceConfig.cmake

pause
