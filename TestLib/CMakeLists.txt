cmake_minimum_required(VERSION 2.8)
project(TestLib)

include(../CMakeDepend.txt)

set(SOURCE_FILES library.cpp library.h)
add_library(TestLib SHARED ${SOURCE_FILES})