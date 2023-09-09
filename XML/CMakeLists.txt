cmake_minimum_required(VERSION 2.8)
project(XML)

include(../CMakeDepend.txt)

set(SOURCE_FILES SAXTest.cpp)
add_executable(SAXTest ${SOURCE_FILES})
target_link_libraries(SAXTest PocoFoundation PocoXML)

set(SOURCE_FILES DOMTest.cpp)
add_executable(DOMTest ${SOURCE_FILES})
target_link_libraries(DOMTest PocoFoundation PocoXML)


