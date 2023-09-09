cmake_minimum_required(VERSION 2.8)
project(Network)

include(../CMakeDepend.txt)

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

