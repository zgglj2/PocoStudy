cmake_minimum_required(VERSION 3.6)
project(Types)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES ByteOrderTest.cpp)
add_executable(ByteOrder ${SOURCE_FILES})

set(ANY_SOURCE_FILES AnyTest.cpp)
add_executable(AnyTest ${ANY_SOURCE_FILES})
target_link_libraries(AnyTest PocoFoundation)

set(DYNAMIC_ANY_SOURCE_FILES DynamicAnyTest.cpp)
add_executable(DynamicAnyTest ${DYNAMIC_ANY_SOURCE_FILES})
target_link_libraries(DynamicAnyTest PocoFoundation)
