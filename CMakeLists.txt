cmake_minimum_required(VERSION 3.24.1)
project(jhelper-project)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

ADD_DEFINITIONS(-std=c++11)

add_executable(test ${TASKS} ${HEADERS})