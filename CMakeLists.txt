cmake_minimum_required(VERSION 3.0)

project(Threading_Exmaple)
set(PROJECT_NAME Threading_Exmaple)
set(PROJECT_NAME1 UnitTest_Exmaple)

find_package(UnitTest++ REQUIRED)
include_directories(${UTPP_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-std=gnu++11")

include_directories(inc)
file(GLOB HEADERS "inc/*.h")
file(GLOB SOURCES src/primary_thread.cpp src/worker_thread.cpp src/main.cpp)
file(GLOB SOURCES_UNIT src/primary_thread.cpp src/worker_thread.cpp src/UnitTest.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_executable(${PROJECT_NAME1} ${SOURCES_UNIT} ${HEADERS})

target_link_libraries(${PROJECT_NAME} pthread UnitTest++)
target_link_libraries(${PROJECT_NAME1} pthread UnitTest++)
