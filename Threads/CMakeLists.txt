cmake_minimum_required(VERSION 3.3)
project(Threads)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

find_package(Threads)

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

set(SOURCE_FILES ConditionTest.cpp)
add_executable(ConditionTest ${SOURCE_FILES})
target_link_libraries(ConditionTest PocoFoundation)

set(SOURCE_FILES EventTest.cpp)
add_executable(EventTest ${SOURCE_FILES})
target_link_libraries(EventTest PocoFoundation)

set(SOURCE_FILES SemaphoreTest.cpp)
add_executable(SemaphoreTest ${SOURCE_FILES})
target_link_libraries(SemaphoreTest PocoFoundation)

set(SOURCE_FILES RWLockTest.cpp)
add_executable(RWLockTest ${SOURCE_FILES})
target_link_libraries(RWLockTest PocoFoundation  ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES TimerTest.cpp)
add_executable(TimerTest ${SOURCE_FILES})
target_link_libraries(TimerTest PocoFoundation)

set(SOURCE_FILES TaskManagerTest.cpp)
add_executable(TaskManagerTest ${SOURCE_FILES})
target_link_libraries(TaskManagerTest PocoFoundation)

set(SOURCE_FILES ActivityTest.cpp)
add_executable(ActivityTest ${SOURCE_FILES})
target_link_libraries(ActivityTest PocoFoundation)

set(SOURCE_FILES ActiveMethodTest.cpp)
add_executable(ActiveMethodTest ${SOURCE_FILES})
target_link_libraries(ActiveMethodTest PocoFoundation)

set(SOURCE_FILES ActiveDispatcherTest.cpp)
add_executable(ActiveDispatcherTest ${SOURCE_FILES})
target_link_libraries(ActiveDispatcherTest PocoFoundation)


