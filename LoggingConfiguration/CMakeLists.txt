cmake_minimum_required(VERSION 2.8.13)
project(LoggingConfiguration)

include(../CMakeDepend.txt)

set(SOURCE_FILES LoggingConfigurationTest.cpp)
add_executable(LoggingConfigurationTest ${SOURCE_FILES})
target_link_libraries(LoggingConfigurationTest PocoFoundation PocoUtil)




