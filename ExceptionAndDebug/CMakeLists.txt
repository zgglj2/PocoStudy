cmake_minimum_required(VERSION 2.8)
project(ExceptionAndDebug)

include(../CMakeDepend.txt)

set(EXCEPTION_SOURCE_FILES MyException.cpp MyExceptionTest.cpp)
add_executable(MyExceptionTest ${EXCEPTION_SOURCE_FILES})
target_link_libraries(MyExceptionTest PocoFoundation)

set(NDC_SOURCE_FILES NDCTest.cpp)
add_executable(NDCTest ${NDC_SOURCE_FILES})
target_link_libraries(NDCTest PocoFoundation)
