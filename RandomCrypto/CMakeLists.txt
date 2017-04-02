cmake_minimum_required(VERSION 3.6)
project(StringAndFormatting)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(RANDOM_SOURCE_FILES RandomTest.cpp)
add_executable(RandomTest ${RANDOM_SOURCE_FILES})
target_link_libraries(RandomTest PocoFoundation)

set(CRYPTO_SOURCE_FILES CryptoHashTest.cpp)
add_executable(CryptoHashTest ${CRYPTO_SOURCE_FILES})
target_link_libraries(CryptoHashTest PocoFoundation)

