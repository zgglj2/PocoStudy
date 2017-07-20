cmake_minimum_required(VERSION 3.3)
project(Cache)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES LRUCacheTest.cpp)
add_executable(LRUCacheTest ${SOURCE_FILES})
target_link_libraries(LRUCacheTest PocoFoundation)

set(SOURCE_FILES UniqueExpireCacheTest.cpp)
add_executable(UniqueExpireCacheTest ${SOURCE_FILES})
target_link_libraries(UniqueExpireCacheTest PocoFoundation)
