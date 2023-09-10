cmake_minimum_required(VERSION 2.8.13)
project(Curl)

include(../CMakeDepend.txt)

set(SOURCE_FILES CurlDownloadTest.cpp)
add_executable(CurlDownloadTest ${SOURCE_FILES})
target_link_libraries(CurlDownloadTest curl)

