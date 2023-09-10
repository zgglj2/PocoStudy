cmake_minimum_required(VERSION 2.8.13)
project(Memory)

include(../CMakeDepend.txt)

set(AUTOPTR_SOURCE_FILES AutoPtrTest.cpp)
add_executable(AutoPtrTest ${AUTOPTR_SOURCE_FILES})
target_link_libraries(AutoPtrTest PocoFoundation)

set(RCO_SOURCE_FILES RefCountedObjectTest.cpp)
add_executable(RefCountedObjectTest ${RCO_SOURCE_FILES})
target_link_libraries(RefCountedObjectTest PocoFoundation)

set(ARP_SOURCE_FILES AutoReleasePoolTest.cpp)
add_executable(AutoReleasePoolTest ${ARP_SOURCE_FILES})
target_link_libraries(AutoReleasePoolTest PocoFoundation)

set(SHAREDPTR_SOURCE_FILES SharedPtrTest.cpp)
add_executable(SharedPtrTest ${SHAREDPTR_SOURCE_FILES})
target_link_libraries(SharedPtrTest PocoFoundation)

set(SHAREDPTRARRAY_SOURCE_FILES SharedPtrArraysTest.cpp)
add_executable(SharedPtrArraysTest ${SHAREDPTRARRAY_SOURCE_FILES})
target_link_libraries(SharedPtrArraysTest PocoFoundation)

set(BUFFER_SOURCE_FILES BufferTest.cpp)
add_executable(BufferTest ${BUFFER_SOURCE_FILES})
target_link_libraries(BufferTest PocoFoundation)

set(SINGLETON_SOURCE_FILES SingletonTest.cpp)
add_executable(SingletonTest ${SINGLETON_SOURCE_FILES})
target_link_libraries(SingletonTest PocoFoundation)

set(MEMPOOL_SOURCE_FILES MemoryPoolTest.cpp)
add_executable(MemoryPoolTest ${MEMPOOL_SOURCE_FILES})
target_link_libraries(MemoryPoolTest PocoFoundation)
