cmake_minimum_required(VERSION 3.3)
project(URIAndUUID)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES URITest.cpp)
add_executable(URITest ${SOURCE_FILES})
target_link_libraries(URITest PocoFoundation)

set(SOURCE_FILES URIStreamOpenerTest.cpp)
add_executable(URIStreamOpenerTest ${SOURCE_FILES})
target_link_libraries(URIStreamOpenerTest PocoFoundation)

