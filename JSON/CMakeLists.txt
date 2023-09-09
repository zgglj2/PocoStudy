cmake_minimum_required(VERSION 2.8)
project(JSON)

include(../CMakeDepend.txt)

set(SOURCE_FILES JSONTest.cpp)
add_executable(JSONTest ${SOURCE_FILES})
target_link_libraries(JSONTest PocoFoundation PocoJSON)


