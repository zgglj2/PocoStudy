cmake_minimum_required(VERSION 2.8)
project(Logging)

include(../CMakeDepend.txt)

set(SOURCE_FILES LoggerTest.cpp)
add_executable(LoggerTest ${SOURCE_FILES})
target_link_libraries(LoggerTest PocoFoundation)

set(SOURCE_FILES SimpleFileChannelTest.cpp)
add_executable(SimpleFileChannelTest ${SOURCE_FILES})
target_link_libraries(SimpleFileChannelTest PocoFoundation)

set(SOURCE_FILES FileChannelTest.cpp)
add_executable(FileChannelTest ${SOURCE_FILES})
target_link_libraries(FileChannelTest PocoFoundation)

set(SOURCE_FILES AsyncChannelTest.cpp)
add_executable(AsyncChannelTest ${SOURCE_FILES})
target_link_libraries(AsyncChannelTest PocoFoundation)

set(SOURCE_FILES SpltterChannelTest.cpp)
add_executable(SpltterChannelTest ${SOURCE_FILES})
target_link_libraries(SpltterChannelTest PocoFoundation)

set(SOURCE_FILES LogStreamTest.cpp)
add_executable(LogStreamTest ${SOURCE_FILES})
target_link_libraries(LogStreamTest PocoFoundation)

set(SOURCE_FILES FormattingChannelTest.cpp)
add_executable(FormattingChannelTest ${SOURCE_FILES})
target_link_libraries(FormattingChannelTest PocoFoundation)

