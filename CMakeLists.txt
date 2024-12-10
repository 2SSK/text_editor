# Minimum required version of CMake to build this project
cmake_minimum_required(VERSION 3.12)
project(text_editor)

find_package(FLTK REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(TextEditor ${SOURCES})

target_include_directories(TextEditor PRIVATE ${FLTK_INCLUDE_DIRS})
target_link_libraries(TextEditor PRIVATE ${FLTK_LIBRARIES})
