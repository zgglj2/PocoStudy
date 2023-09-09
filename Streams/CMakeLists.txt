cmake_minimum_required(VERSION 2.8)
project(Streams)

include(../CMakeDepend.txt)

set(SOURCE_FILES EncodeAndDecodeTest.cpp)
add_executable(EncodeAndDecodeTest ${SOURCE_FILES})
target_link_libraries(EncodeAndDecodeTest PocoFoundation)

set(SOURCE_FILES ZlibTest.cpp)
add_executable(ZlibTest ${SOURCE_FILES})
target_link_libraries(ZlibTest PocoFoundation)

set(SOURCE_FILES CountingTest.cpp)
add_executable(CountingTest ${SOURCE_FILES})
target_link_libraries(CountingTest PocoFoundation)

set(SOURCE_FILES SplitStreamsTest.cpp)
add_executable(SplitStreamsTest ${SOURCE_FILES})
target_link_libraries(SplitStreamsTest PocoFoundation)

set(SOURCE_FILES BinaryTest.cpp)
add_executable(BinaryTest ${SOURCE_FILES})
target_link_libraries(BinaryTest PocoFoundation)

set(SOURCE_FILES FileStreamTest.cpp)
add_executable(FileStreamTest ${SOURCE_FILES})
target_link_libraries(FileStreamTest PocoFoundation)
