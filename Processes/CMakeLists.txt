cmake_minimum_required(VERSION 3.3)
project(Processes)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES ProcessTest.cpp)
add_executable(ProcessTest ${SOURCE_FILES})
target_link_libraries(ProcessTest PocoFoundation)

set(SOURCE_FILES PipeTest.cpp)
add_executable(PipeTest ${SOURCE_FILES})
target_link_libraries(PipeTest PocoFoundation)

set(SOURCE_FILES SharedMemoryTest.cpp)
add_executable(SharedMemoryTest ${SOURCE_FILES})
target_link_libraries(SharedMemoryTest PocoFoundation)

