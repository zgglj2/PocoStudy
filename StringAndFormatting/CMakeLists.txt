cmake_minimum_required(VERSION 3.6)
project(StringAndFormatting)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(TRIM_SOURCE_FILES TrimTest.cpp)
add_executable(TrimTest ${TRIM_SOURCE_FILES})
target_link_libraries(TrimTest PocoFoundation)

set(CASE_SOURCE_FILES CaseTest.cpp)
add_executable(CaseTest ${CASE_SOURCE_FILES})
target_link_libraries(CaseTest PocoFoundation)

set(REPLACE_SOURCE_FILES ReplaceTest.cpp)
add_executable(ReplaceTest ${REPLACE_SOURCE_FILES})
target_link_libraries(ReplaceTest PocoFoundation)

set(CAT_SOURCE_FILES CatTest.cpp)
add_executable(CatTest ${CAT_SOURCE_FILES})
target_link_libraries(CatTest PocoFoundation)

set(NUMFMT_SOURCE_FILES NumberFormatterTest.cpp)
add_executable(NumberFormatterTest ${NUMFMT_SOURCE_FILES})
target_link_libraries(NumberFormatterTest PocoFoundation)

set(FMT_SOURCE_FILES FormatTest.cpp)
add_executable(FormatTest ${FMT_SOURCE_FILES})
target_link_libraries(FormatTest PocoFoundation)

set(STRINGTOKEN_SOURCE_FILES StringTokenizerTest.cpp)
add_executable(StringTokenizerTest ${STRINGTOKEN_SOURCE_FILES})
target_link_libraries(StringTokenizerTest PocoFoundation)

set(RE_SOURCE_FILES RegularExpressionTest.cpp)
add_executable(RegularExpressionTest ${RE_SOURCE_FILES})
target_link_libraries(RegularExpressionTest PocoFoundation)

set(TEXTCONVERTER_SOURCE_FILES TextConverterTest.cpp)
add_executable(TextConverterTest ${TEXTCONVERTER_SOURCE_FILES})
target_link_libraries(TextConverterTest PocoFoundation)

set(NUMBERPARSER_SOURCE_FILES NumberParserTest.cpp)
add_executable(NumberParserTest ${NUMBERPARSER_SOURCE_FILES})
target_link_libraries(NumberParserTest PocoFoundation)
