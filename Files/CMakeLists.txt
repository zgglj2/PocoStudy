cmake_minimum_required(VERSION 3.6)
project(Files)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")
link_directories("../../poco-1.7.8/cmake-build-release/bin")

set(SOURCE_FILES PathTest.cpp)
add_executable(PathTest ${SOURCE_FILES})
target_link_libraries(PathTest PocoFoundation)

set(SOURCE_FILES FilesTest.cpp)
add_executable(FilesTest ${SOURCE_FILES})
target_link_libraries(FilesTest PocoFoundation)

set(SOURCE_FILES DirectoryIteratorTest.cpp)
add_executable(DirectoryIteratorTest ${SOURCE_FILES})
target_link_libraries(DirectoryIteratorTest PocoFoundation)

set(SOURCE_FILES GlobTest.cpp)
add_executable(GlobTest ${SOURCE_FILES})
target_link_libraries(GlobTest PocoFoundation)

set(SOURCE_FILES TemporaryFileTest.cpp)
add_executable(TemporaryFileTest ${SOURCE_FILES})
target_link_libraries(TemporaryFileTest PocoFoundation)

set(SOURCE_FILES FileLockTest.cpp)
add_executable(FileLockTest ${SOURCE_FILES})
target_link_libraries(FileLockTest PocoFoundation)
