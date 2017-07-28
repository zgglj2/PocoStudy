cmake_minimum_required(VERSION 3.3)
project(Network)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
include_directories("../../poco-1.7.8/Net/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES DNSTest.cpp)
add_executable(DNSTest ${SOURCE_FILES})
target_link_libraries(DNSTest PocoFoundation PocoNet)

set(SOURCE_FILES StreamSocketTest.cpp)
add_executable(StreamSocketTest ${SOURCE_FILES})
target_link_libraries(StreamSocketTest PocoFoundation PocoNet)

set(SOURCE_FILES ServerSocketTest.cpp)
add_executable(ServerSocketTest ${SOURCE_FILES})
target_link_libraries(ServerSocketTest PocoFoundation PocoNet)

