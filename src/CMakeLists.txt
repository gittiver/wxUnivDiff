set(PROGRAM_wxUnivDiff "wxUnivDiff")
set(PROGRAM_wxUnivDiff_SOURCES  
        wxUnivDiffApp.cpp wxUnivDiffApp.hpp 
        MainFrame.cpp MainFrame.h
    ui.cpp ui.h
)

include(${CMAKE_ROOT}/Modules/FindwxWidgets.cmake)
include(${CMAKE_ROOT}/Modules/UsewxWidgets.cmake)

# Here you can define what libraries of wxWidgets you need for your
# application. You can figure out what libraries you need here;
# http://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html

# We need the Find package for wxWidgets to work
find_package(wxWidgets REQUIRED base core adv)

##---------------------------------------------------
## Actual config file starts here
##--------------------------------------------------- 
 
# Did we find wxWidgets ? This condition will fail
# for as long as the internal vars do not point to
# the proper wxWidgets configuration
if(wxWidgets_FOUND)
#        message(wxWidgets_ROOT_DIR=${wxWidgets_ROOT_DIR})
#        message(wxWidgets_LIB_DIR=${wxWidgets_LIB_DIR})

    # Include wxWidgets macros
    include(${wxWidgets_USE_FILE})

    # We define the include paths here, our minimal source dir is one, 
    # and also the include dirs defined by wxWidgets
#    include_directories(
#                        ${EXPAT_INCLUDE_DIRS}
#                        ../../library 
#                        ../../generator
#                        )
    set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS ${wxWidgets_DEFINITIONS})
 
    # Here we define the executable wxUnivDiffApp
    # the above paths and defines will be used in this build
    
    add_executable(${PROGRAM_wxUnivDiff} 
                   WIN32 MACOSX_BUNDLE
                   ${PROGRAM_wxUnivDiff_SOURCES})

    #ui-access
    target_link_libraries(${PROGRAM_wxUnivDiff} ${wxWidgets_LIBRARIES})

    if (MSVC)
        set_property(TARGET ${PROGRAM_wxUnivDiff} 
					 APPEND PROPERTY LINK_FLAGS /INCREMENTAL:NO) 
        target_link_libraries(${PROGRAM_wxUnivDiff} gdiplus.lib)
    endif(MSVC)
    install(TARGETS ${PROGRAM_wxUnivDiff}
                RUNTIME DESTINATION bin 
                BUNDLE DESTINATION Applications)    

else(wxWidgets_FOUND)
    # For convenience. When we cannot continue, inform the user
    MESSAGE("wxWidgets not found!")
endif(wxWidgets_FOUND)

