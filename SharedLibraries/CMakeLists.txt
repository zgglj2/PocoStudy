cmake_minimum_required(VERSION 3.3)
project(SharedLibraries)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES TestLibrary.cpp)
add_library(TestLibrary SHARED ${SOURCE_FILES})

set(ENV_SOURCE_FILES SharedLibraryTest.cpp)
add_executable(SharedLibraryTest ${ENV_SOURCE_FILES})
target_link_libraries(SharedLibraryTest PocoFoundation)

set(SOURCE_FILES AbstractPlugin.cpp)
add_library(AbstractPlugin SHARED ${SOURCE_FILES})
target_link_libraries(AbstractPlugin PocoFoundation)

set(SOURCE_FILES PluginLibrary.cpp)
add_library(PluginLibrary SHARED ${SOURCE_FILES})
target_link_libraries(PluginLibrary AbstractPlugin)

set(ENV_SOURCE_FILES ClassLoaderTest.cpp)
add_executable(ClassLoaderTest ${ENV_SOURCE_FILES})
target_link_libraries(ClassLoaderTest PocoFoundation)
