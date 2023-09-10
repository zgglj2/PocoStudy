cmake_minimum_required(VERSION 2.8.13)
project(Processes)

include(../CMakeDepend.txt)

set(SOURCE_FILES ProcessTest.cpp)
add_executable(ProcessTest ${SOURCE_FILES})
target_link_libraries(ProcessTest PocoFoundation)

set(SOURCE_FILES PipeTest.cpp)
add_executable(PipeTest ${SOURCE_FILES})
target_link_libraries(PipeTest PocoFoundation)

set(SOURCE_FILES SharedMemoryTest.cpp)
add_executable(SharedMemoryTest ${SOURCE_FILES})
target_link_libraries(SharedMemoryTest PocoFoundation)

