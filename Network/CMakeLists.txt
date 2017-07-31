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

set(SOURCE_FILES DatagramSocketRecvTest.cpp)
add_executable(DatagramSocketRecvTest ${SOURCE_FILES})
target_link_libraries(DatagramSocketRecvTest PocoFoundation PocoNet)

set(SOURCE_FILES DatagramSocketSendTest.cpp)
add_executable(DatagramSocketSendTest ${SOURCE_FILES})
target_link_libraries(DatagramSocketSendTest PocoFoundation PocoNet)

set(SOURCE_FILES MulticastSocketRecvTest.cpp)
add_executable(MulticastSocketRecvTest ${SOURCE_FILES})
target_link_libraries(MulticastSocketRecvTest PocoFoundation PocoNet)

