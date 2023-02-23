set(PROGRAM_wxUnivDiff "wxUnivDiff")

set(LIB_libwxUnivDiff_SOURCES
    ui.cpp ui.h
    cmdline.hpp cmdline.cpp 
    extensionconfiguration.hpp extensionconfiguration.cpp
    MimeTypeListFrame.hpp MimeTypeListFrame.cpp
)

set(PROGRAM_wxUnivDiff_SOURCES
        wxUnivDiffApp.cpp wxUnivDiffApp.hpp
)

# Did we find wxWidgets ? This condition will fail
# for as long as the internal vars do not point to
# the proper wxWidgets configuration
if(wxWidgets_FOUND)
    # Here we define the executable wxUnivDiffApp
    # the above paths and defines will be used in this build
    
    add_library(libwxunivDiff ${LIB_libwxUnivDiff_SOURCES})


  if(APPLE)
    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    add_executable(${PROGRAM_wxUnivDiff}
                   WIN32 MACOSX_BUNDLE
                   ${PROGRAM_wxUnivDiff_SOURCES})
    set_target_properties(${PROGRAM_wxUnivDiff} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function. This is ignored on other systems,
    # so it works on all platforms
    add_executable(${PROGRAM_wxUnivDiff} WIN32 ${SRCS} main.exe.manifest)
endif()
      target_link_libraries(${PROGRAM_wxUnivDiff} ${wxWidgets_LIBRARIES} "libwxunivDiff")

    if (MSVC)
        set_property(TARGET ${PROGRAM_wxUnivDiff}
					 APPEND PROPERTY LINK_FLAGS /INCREMENTAL:NO)
        target_link_libraries(${PROGRAM_wxUnivDiff} gdiplus.lib)
    endif(MSVC)
    install(TARGETS ${PROGRAM_wxUnivDiff}
                RUNTIME DESTINATION bin
                BUNDLE DESTINATION Applications)

else(wxWidgets_FOUND)
endif(wxWidgets_FOUND)

