cmake_minimum_required(VERSION 3.0)
project(Threading_Exmaple)

find_package(UnitTest++ REQUIRED)
include_directories(${UTPP_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

include_directories(inc)
set(SOURCE_FILES main.cpp worker_thread.h)

add_executable(Threading_Exmaple ${SOURCE_FILES})

target_link_libraries(Threading_Exmaple pthread UnitTest++)
