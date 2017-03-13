cmake_minimum_required(VERSION 3.6)
project(Types)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/bin")

set(SOURCE_FILES TypesTest.cpp)
add_executable(Types ${SOURCE_FILES})

#target_link_libraries(Types cygPocoFoundation.dll)