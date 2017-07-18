cmake_minimum_required(VERSION 3.3)
project(Threads)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES ThreadTest.cpp)
add_executable(ThreadTest ${SOURCE_FILES})
target_link_libraries(ThreadTest PocoFoundation)

set(SOURCE_FILES ThreadPoolTest.cpp)
add_executable(ThreadPoolTest ${SOURCE_FILES})
target_link_libraries(ThreadPoolTest PocoFoundation)

set(SOURCE_FILES ThreadLocalTest.cpp)
add_executable(ThreadLocalTest ${SOURCE_FILES})
target_link_libraries(ThreadLocalTest PocoFoundation)

set(SOURCE_FILES ErrorHandlerTest.cpp)
add_executable(ErrorHandlerTest ${SOURCE_FILES})
target_link_libraries(ErrorHandlerTest PocoFoundation)

set(SOURCE_FILES MutexTest.cpp)
add_executable(MutexTest ${SOURCE_FILES})
target_link_libraries(MutexTest PocoFoundation)

set(SOURCE_FILES FastMutexTest.cpp)
add_executable(FastMutexTest ${SOURCE_FILES})
target_link_libraries(FastMutexTest PocoFoundation)

set(SOURCE_FILES ScopeLockTest.cpp)
add_executable(ScopeLockTest ${SOURCE_FILES})
target_link_libraries(ScopeLockTest PocoFoundation)


