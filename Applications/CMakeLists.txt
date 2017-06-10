cmake_minimum_required(VERSION 3.6)
project(Applications)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
include_directories("../../poco-1.7.8/Util/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(APPLICATION_SOURCE_FILES ApplicationTest.cpp)
add_executable(ApplicationTest ${APPLICATION_SOURCE_FILES})
target_link_libraries(ApplicationTest PocoFoundation PocoUtil)

set(SAMPLEAPPP_SOURCE_FILES SampleApp.cpp)
add_executable(SampleApp ${SAMPLEAPPP_SOURCE_FILES})
target_link_libraries(SampleApp PocoFoundation PocoUtil)



