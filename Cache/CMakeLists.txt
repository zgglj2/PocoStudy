cmake_minimum_required(VERSION 2.8)
project(Cache)

include(../CMakeDepend.txt)

set(SOURCE_FILES LRUCacheTest.cpp)
add_executable(LRUCacheTest ${SOURCE_FILES})
target_link_libraries(LRUCacheTest PocoFoundation)

set(SOURCE_FILES UniqueExpireCacheTest.cpp)
add_executable(UniqueExpireCacheTest ${SOURCE_FILES})
target_link_libraries(UniqueExpireCacheTest PocoFoundation)
