cmake_minimum_required(VERSION 3.3)
project(TestLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h)
add_library(TestLib SHARED ${SOURCE_FILES})