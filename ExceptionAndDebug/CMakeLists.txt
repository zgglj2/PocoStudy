cmake_minimum_required(VERSION 3.6)
project(ExceptionAndDebug)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(EXCEPTION_SOURCE_FILES MyException.cpp MyExceptionTest.cpp)
add_executable(MyExceptionTest ${EXCEPTION_SOURCE_FILES})
target_link_libraries(MyExceptionTest PocoFoundation)

set(NDC_SOURCE_FILES NDCTest.cpp)
add_executable(NDCTest ${NDC_SOURCE_FILES})
target_link_libraries(NDCTest PocoFoundation)
