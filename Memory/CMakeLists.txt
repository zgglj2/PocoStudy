cmake_minimum_required(VERSION 3.6)
project(Memory)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(AUTOPTR_SOURCE_FILES AutoPtrTest.cpp)
add_executable(AutoPtrTest ${AUTOPTR_SOURCE_FILES})
target_link_libraries(AutoPtrTest PocoFoundation)

set(RCO_SOURCE_FILES RefCountedObjectTest.cpp)
add_executable(RefCountedObjectTest ${RCO_SOURCE_FILES})
target_link_libraries(RefCountedObjectTest PocoFoundation)
