cmake_minimum_required(VERSION 3.16)

project(qingshan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/../3rdPart/libMta)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appqingshan
    "main.cpp"
    "UIhandler/dlgmain.h"
    "UIhandler/dlgmain.cpp"
    "win/shapi.h"
    "win/shapi.cpp"
    "win/regEdit.h"
    "win/regEdit.cpp"
    "stringTable.h"
)
#请求管理员
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")


qt_add_qml_module(appqingshan
    URI qingshan
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appqingshan PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    IMPORTED_LOCATION  ${CMAKE_CURRENT_SOURCE_DIR}/../3rdPart/${CMAKE_BUILD_TYPE}
)

target_link_libraries(appqingshan
    PRIVATE Qt6::Quick
)

install(TARGETS appqingshan
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../3rdPart/libMta/libMta  libMta)


