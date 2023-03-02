cmake_minimum_required(VERSION 3.14)

project(model_interface VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(example_model_1)
add_subdirectory(example_model_2)
add_subdirectory(app)
add_subdirectory(plugincore)
add_subdirectory(qmlplot)
