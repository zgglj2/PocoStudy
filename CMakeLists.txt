cmake_minimum_required(VERSION 3.6)
project(PocoStudy)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Types)
add_subdirectory(ExceptionAndDebug)
add_subdirectory(Memory)
add_subdirectory(StringAndFormatting)
add_subdirectory(PlatformAndEnvironment)
add_subdirectory(RandomCrypto)
add_subdirectory(Files)
add_subdirectory(TestLib)
add_subdirectory(Curl)

set(SOURCE_FILES main.cpp)
add_executable(PocoStudy ${SOURCE_FILES})
#target_link_libraries(PocoStudy cygPocoFoundation.dll)