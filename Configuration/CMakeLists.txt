cmake_minimum_required(VERSION 2.8.13)
project(Configuration)

include(../CMakeDepend.txt)

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
