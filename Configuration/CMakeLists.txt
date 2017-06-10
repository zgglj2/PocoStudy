cmake_minimum_required(VERSION 3.6)
project(Configuration)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
include_directories("../../poco-1.7.8/XML/include")
include_directories("../../poco-1.7.8/Util/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(XML_SOURCE_FILES XMLConfigurationTest.cpp)
add_executable(XMLConfigurationTest ${XML_SOURCE_FILES})
target_link_libraries(XMLConfigurationTest PocoFoundation PocoUtil)

set(INI_SOURCE_FILES INIConfigurationTest.cpp)
add_executable(INIConfigurationTest ${INI_SOURCE_FILES})
target_link_libraries(INIConfigurationTest PocoFoundation PocoUtil)

set(PROPERTY_SOURCE_FILES PropertyConfigurationTest.cpp)
add_executable(PropertyConfigurationTest ${PROPERTY_SOURCE_FILES})
target_link_libraries(PropertyConfigurationTest PocoFoundation PocoUtil)

set(MAP_SOURCE_FILES MapConfigurationTest.cpp)
add_executable(MapConfigurationTest ${MAP_SOURCE_FILES})
target_link_libraries(MapConfigurationTest PocoFoundation PocoUtil)
