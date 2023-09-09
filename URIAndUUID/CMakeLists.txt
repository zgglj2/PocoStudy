cmake_minimum_required(VERSION 2.8)
project(URIAndUUID)

include(../CMakeDepend.txt)

set(SOURCE_FILES URITest.cpp)
add_executable(URITest ${SOURCE_FILES})
target_link_libraries(URITest PocoFoundation)

set(SOURCE_FILES URIStreamOpenerTest.cpp)
add_executable(URIStreamOpenerTest ${SOURCE_FILES})
target_link_libraries(URIStreamOpenerTest PocoFoundation PocoNet)

set(SOURCE_FILES UUIDTest.cpp)
add_executable(UUIDTest ${SOURCE_FILES})
target_link_libraries(UUIDTest PocoFoundation)

