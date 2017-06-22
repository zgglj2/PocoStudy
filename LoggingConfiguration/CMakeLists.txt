cmake_minimum_required(VERSION 3.6)
project(Applications)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
include_directories("../../poco-1.7.8/Util/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES LoggingConfigurationTest.cpp)
add_executable(LoggingConfigurationTest ${SOURCE_FILES})
target_link_libraries(LoggingConfigurationTest PocoFoundation PocoUtil)




