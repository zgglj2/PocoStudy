cmake_minimum_required(VERSION 3.6)
project(DateAndTime)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(TIMESTAMP_SOURCE_FILES TimeStampTest.cpp)
add_executable(TimeStampTest ${TIMESTAMP_SOURCE_FILES})
target_link_libraries(TimeStampTest PocoFoundation)


