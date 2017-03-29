cmake_minimum_required(VERSION 3.6)
project(Curl)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES CurlDownloadTest.cpp)
add_executable(CurlDownloadTest ${SOURCE_FILES})
target_link_libraries(CurlDownloadTest curl)

