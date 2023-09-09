cmake_minimum_required(VERSION 2.8)
project(Applications)

include(../CMakeDepend.txt)

set(APPLICATION_SOURCE_FILES ApplicationTest.cpp)
add_executable(ApplicationTest ${APPLICATION_SOURCE_FILES})
target_link_libraries(ApplicationTest PocoFoundation PocoUtil)

set(SAMPLEAPPP_SOURCE_FILES SampleApp.cpp)
add_executable(SampleApp ${SAMPLEAPPP_SOURCE_FILES})
target_link_libraries(SampleApp PocoFoundation PocoUtil)

set(SERVERAPPP_SOURCE_FILES SampleServer.cpp)
add_executable(SampleServer ${SERVERAPPP_SOURCE_FILES})
target_link_libraries(SampleServer PocoFoundation PocoUtil)



