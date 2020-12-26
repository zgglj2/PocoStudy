cmake_minimum_required(VERSION 3.3)
project(JSON)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
include_directories("../../poco-1.7.8/XML/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES JSONTest.cpp)
add_executable(JSONTest ${SOURCE_FILES})
target_link_libraries(JSONTest PocoFoundation PocoJSON)


