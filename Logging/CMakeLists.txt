cmake_minimum_required(VERSION 3.3)
project(Logging)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES LoggerTest.cpp)
add_executable(LoggerTest ${SOURCE_FILES})
target_link_libraries(LoggerTest PocoFoundation)

