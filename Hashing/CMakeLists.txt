cmake_minimum_required(VERSION 2.8.13)
project(Hashing)

include(../CMakeDepend.txt)

set(SOURCE_FILES LinearHashTableTest.cpp)
add_executable(LinearHashTableTest ${SOURCE_FILES})
target_link_libraries(LinearHashTableTest PocoFoundation)

set(SOURCE_FILES HashMapTest.cpp)
add_executable(HashMapTest ${SOURCE_FILES})
target_link_libraries(HashMapTest PocoFoundation)

set(SOURCE_FILES HashSetTest.cpp)
add_executable(HashSetTest ${SOURCE_FILES})
target_link_libraries(HashSetTest PocoFoundation)

