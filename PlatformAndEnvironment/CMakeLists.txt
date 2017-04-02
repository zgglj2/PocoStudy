cmake_minimum_required(VERSION 3.6)
project(StringAndFormatting)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(PLATFORM_SOURCE_FILES PlatformTest.cpp)
add_executable(PlatformTest ${PLATFORM_SOURCE_FILES})
target_link_libraries(PlatformTest PocoFoundation)

set(ENV_SOURCE_FILES EnvironmentTest.cpp)
add_executable(EnvironmentTest ${ENV_SOURCE_FILES})
target_link_libraries(EnvironmentTest PocoFoundation)

