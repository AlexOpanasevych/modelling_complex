#project(example_model_1 VERSION 0.1 LANGUAGES CXX)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
        model1.cpp
        model1.h
        example_model_1_plugin.cpp
        example_model_1_plugin.h
        qmldir
)

add_library(example_model_1 SHARED ${PROJECT_SOURCES})

include_directories(../plugincore)

target_compile_definitions(example_model_1
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(example_model_1
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick plugincore)


#install(FILES ${PROJECT_BINARY_DIR}/$<CONFIG>/example_model_1
#DESTINATION bin)


#install(FILES ${PROJECT_BINARY_DIR}/$<CONFIG>/example_model_2
#DESTINATION bin)
