cmake_minimum_required(VERSION 3.6)
project(Files)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")
link_directories("../../poco-1.7.8/cmake-build-release/bin")

set(SOURCE_FILES FilesTest.cpp)
add_executable(Files ${SOURCE_FILES})
target_link_libraries(Files PocoFoundation)

set(SOURCE_FILES GlobTest.cpp)
add_executable(GlobTest ${SOURCE_FILES})
target_link_libraries(GlobTest PocoFoundation)

set(SOURCE_FILES TemporaryFileTest.cpp)
add_executable(TemporaryFileTest ${SOURCE_FILES})
target_link_libraries(TemporaryFileTest PocoFoundation)
