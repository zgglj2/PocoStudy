cmake_minimum_required(VERSION 2.8)
project(PlatformAndEnvironment)

include(../CMakeDepend.txt)

set(PLATFORM_SOURCE_FILES PlatformTest.cpp)
add_executable(PlatformTest ${PLATFORM_SOURCE_FILES})
target_link_libraries(PlatformTest PocoFoundation)

set(ENV_SOURCE_FILES EnvironmentTest.cpp)
add_executable(EnvironmentTest ${ENV_SOURCE_FILES})
target_link_libraries(EnvironmentTest PocoFoundation)

