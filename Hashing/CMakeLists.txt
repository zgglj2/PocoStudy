cmake_minimum_required(VERSION 3.3)
project(Hashing)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES LinearHashTableTest.cpp)
add_executable(LinearHashTableTest ${SOURCE_FILES})
target_link_libraries(LinearHashTableTest PocoFoundation)

set(SOURCE_FILES HashMapTest.cpp)
add_executable(HashMapTest ${SOURCE_FILES})
target_link_libraries(HashMapTest PocoFoundation)

set(SOURCE_FILES HashSetTest.cpp)
add_executable(HashSetTest ${SOURCE_FILES})
target_link_libraries(HashSetTest PocoFoundation)

