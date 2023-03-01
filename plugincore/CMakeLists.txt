cmake_minimum_required(VERSION 3.14)

project(plugincore VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_compile_definitions(PLUGINCORE_LIB)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
    plugincore_global.h
    abstractplugininterface.h
    abstractplugininterface.cpp
    abstractmodel.h
    abstractmodel.cpp
    common.h
)

#target_compile_definitions(plugincore
#  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
#target_link_libraries(plugincore
#  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

#set_target_properties(plugincore PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#)


add_library(plugincore SHARED ${PROJECT_SOURCES})

target_compile_definitions(plugincore
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(plugincore
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
#set_target_properties(plugincore PROPERTIES
#    VERSION ${PROJECT_VERSION}
#    SOVERSION ${SO_VERSION}
#    EXPORT_NAME plugincore
#)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(plugincore)
    qt_finalize_executable(plugincore)
endif()
