cmake_minimum_required(VERSION 2.8.13)
project(RandomCrypto)

include(../CMakeDepend.txt)

set(RANDOM_SOURCE_FILES RandomTest.cpp)
add_executable(RandomTest ${RANDOM_SOURCE_FILES})
target_link_libraries(RandomTest PocoFoundation)

set(CRYPTO_SOURCE_FILES CryptoHashTest.cpp)
add_executable(CryptoHashTest ${CRYPTO_SOURCE_FILES})
target_link_libraries(CryptoHashTest PocoFoundation)

