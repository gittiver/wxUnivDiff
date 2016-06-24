cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

if(POLICY CMP0043)
  cmake_policy(SET CMP0043 OLD)
endif()

set(PARAM_VERSION_MAJOR 0)
set(PARAM_VERSION_MINOR 0)
set(PARAM_VERSION_PATCH 2)
set(PARAM_VERSION ${PARAM_VERSION_MAJOR}.${PARAM_VERSION_MINOR}.${PARAM_VERSION_PATCH} )

project(wxUnivDiff VERSION ${PARAM_VERSION})

include (${CMAKE_ROOT}/Modules/FindCxxTest.cmake)

option(${PROJECT_NAME}_WITH_DOCS "generate Documentation" OFF)
option(${PROJECT_NAME}_WITH_TESTS "enable testing" ON)
option(CMAKE_SUPPRESS_REGENERATION "suppress rules to re-run cmake on changes (warning: no dependency checks!)?" OFF)

if (MSVC)
  option(${PROJECT_NAME}_LINK_MSVC_MT "link with /MT instead of /MD (use msvc runtime dlls versus static linked)" ON) 
  # see http://msdn.microsoft.com/en-us/library/2kzt1wy3%28VS.71%29.aspx   
  if (${PROJECT_NAME}_LINK_MSVC_MT)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  endif (${PROJECT_NAME}_LINK_MSVC_MT)

  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /INCREMENTAL:NO")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W4")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W4")

  set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS _CRT_SECURE_NO_WARNINGS UNICODE)
    set(CMAKE_FIND_LIBRARY_PREFIXES "")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
    set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")          # lib
    set(CMAKE_SHARED_LIBRARY_SUFFIX ".dll")          # .so
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_IMPORT_LIBRARY_SUFFIX ".lib")
    set(CMAKE_EXECUTABLE_SUFFIX ".exe")          # .exe
    set(CMAKE_LINK_LIBRARY_SUFFIX ".lib")
    set(CMAKE_DL_LIBS "")
    set(CMAKE_DEBUG_POSTFIX "d") 
    add_definitions(-DUNICODE -D_UNICODE)
else(MSVC)
  list(APPEND CMAKE_CXX_FLAGS "-Wall -Wunused-variable -Wno-long-long")
   #-pedantic 
  list(APPEND CMAKE_C_FLAGS "-Wall -Wunused-variable -Wno-long-long")
endif(MSVC)

include(${CMAKE_ROOT}/Modules/FindwxWidgets.cmake)
include(${CMAKE_ROOT}/Modules/UsewxWidgets.cmake)

# Here you can define what libraries of wxWidgets you need for your
# application. You can figure out what libraries you need here;
# http://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html

# We need the Find package for wxWidgets to work
find_package(wxWidgets REQUIRED core base)
# adv aui)

##---------------------------------------------------
## Actual config file starts here
##---------------------------------------------------

# Did we find wxWidgets ? This condition will fail
# for as long as the internal vars do not point to
# the proper wxWidgets configuration
if(wxWidgets_FOUND)
    # Include wxWidgets macros
    include(${wxWidgets_USE_FILE})
    set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS ${wxWidgets_DEFINITIONS})
else(wxWidgets_FOUND)
    # For convenience. When we cannot continue, inform the user
    MESSAGE("wxWidgets not found!")
endif(wxWidgets_FOUND)

# create config.h
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake 
        ${CMAKE_CURRENT_BINARY_DIR}/config.h)

# set include directories
get_filename_component(CONFIG_INCLUDE ${CMAKE_CURRENT_BINARY_DIR}/config.h PATH)
include_directories(include ${CONFIG_INCLUDE} ${BACKEND_INCLUDES})

install(DIRECTORY include DESTINATION . 
    COMPONENT devel 
    FILES_MATCHING PATTERN "*.hpp"
    PATTERN .svn EXCLUDE 
    )
install(DIRECTORY include DESTINATION . 
    COMPONENT devel 
    FILES_MATCHING PATTERN "*.h"
    PATTERN .svn EXCLUDE 
    )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config.h 
    DESTINATION include/${PROJECT_NAME} 
    COMPONENT devel)

#include_directories()

add_subdirectory(src)

if (${PROJECT_NAME}_WITH_DOCS)
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
		add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
						WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
						COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
	endif(DOXYGEN_FOUND)
endif(${PROJECT_NAME}_WITH_DOCS)

if(${PROJECT_NAME}_WITH_TESTS) 
  if(CXXTEST_FOUND)
    enable_testing()
    add_subdirectory(test)
  endif(CXXTEST_FOUND)
endif(${PROJECT_NAME}_WITH_TESTS)

include(InstallRequiredSystemLibraries)

set(CPACK_GENERATOR TGZ ZIP)
if(WIN32 AND NOT CYGWIN)
  set(CPACK_GENERATOR NSIS ${CPACK_GENERATOR})
endif(WIN32 AND NOT CYGWIN)
if(APPLE)
  set(CPACK_GENERATOR DragNDrop ${CPACK_GENERATOR})
endif(APPLE)
if (UNIX AND NOT APPLE AND NOT WIN32)
  set(CPACK_GENERATOR DEB ${CPACK_GENERATOR})
endif (UNIX AND NOT APPLE AND NOT WIN32)

set(CPACK_SOURCE_PACKAGE_FILE_NAME ${PROJECT_NAME}-src-${PROJECT_VERSION})
set(CPACK_SOURCE_GENERATOR TGZ ZIP)
set(CPACK_PACKAGE_CONTACT gulliver@users.sourceforge.net) 
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "${PROJECT_NAME} Development Team")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/readme.txt")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_SOURCE_IGNORE_FILES "/docs/html;/autom4te.cache;/build/;/win32/;/.svn/;.git/;~$;${CPACK_SOURCE_IGNORE_FILES}")

if(WIN32 AND NOT UNIX)
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}\\\\${PROJECT_VERSION}")
  # There is a bug in NSI that does not handle full unix paths properly. Make
  # sure there is at least one set of four (4) backlasshes.
  #  set(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
  set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\${PROJECT_NAME}.exe")
  set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} ${PROJECT_NAME}")
  set(CPACK_NSIS_HELP_LINK "http://softwareschmied.net/")
  set(CPACK_NSIS_URL_INFO_ABOUT "http://softwareschmied.net/")
  set(CPACK_NSIS_CONTACT "gulliver@softwareschmied.net")
  set(CPACK_NSIS_MODIFY_PATH ON)
  set(CPACK_NSIS_MENU_LINKS "doc/html/index.html;Documentation")
else(WIN32 AND NOT UNIX)
  set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME}/${PROJECT_VERSION}")
  set(CPACK_STRIP_FILES "bin/${PROJECT_NAME}")
  set(CPACK_SOURCE_STRIP_FILES "")
endif(WIN32 AND NOT UNIX)
set(CPACK_PACKAGE_EXECUTABLES ${PROJECT_NAME};${PROJECT_NAME})
include(CPack)
