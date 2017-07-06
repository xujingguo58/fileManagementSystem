cmake_minimum_required(VERSION 3.6)
project(file)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp user.cpp)
add_executable(file ${SOURCE_FILES})