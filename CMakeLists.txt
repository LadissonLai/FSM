cmake_minimum_required(VERSION 2.8)
project(fsm)

set(CMAKE_BUILD_TYPE release)
aux_source_directory(src SRC_DIR)
include_directories(include)

add_executable(fsm main.cpp ${SRC_DIR})
message(STATUS "SRC DIR is: ${SRC_DIR}")
target_link_libraries(fsm pthread)