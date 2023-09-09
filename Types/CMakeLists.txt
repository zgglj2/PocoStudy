cmake_minimum_required(VERSION 2.8)
project(Types)

include(../CMakeDepend.txt)

set(SOURCE_FILES ByteOrderTest.cpp)
add_executable(ByteOrder ${SOURCE_FILES})

set(ANY_SOURCE_FILES AnyTest.cpp)
add_executable(AnyTest ${ANY_SOURCE_FILES})
target_link_libraries(AnyTest PocoFoundation)

set(DYNAMIC_ANY_SOURCE_FILES DynamicAnyTest.cpp)
add_executable(DynamicAnyTest ${DYNAMIC_ANY_SOURCE_FILES})
target_link_libraries(DynamicAnyTest PocoFoundation)
