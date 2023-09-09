cmake_minimum_required(VERSION 2.8)
project(DateAndTime)

include(../CMakeDepend.txt)

set(TIMESTAMP_SOURCE_FILES TimeStampTest.cpp)
add_executable(TimeStampTest ${TIMESTAMP_SOURCE_FILES})
target_link_libraries(TimeStampTest PocoFoundation)

set(DATETIME_SOURCE_FILES DateTimeTest.cpp)
add_executable(DateTimeTest ${DATETIME_SOURCE_FILES})
target_link_libraries(DateTimeTest PocoFoundation)

set(LOCALDATETIME_SOURCE_FILES LocalDateTimeTest.cpp)
add_executable(LocalDateTimeTest ${LOCALDATETIME_SOURCE_FILES})
target_link_libraries(LocalDateTimeTest PocoFoundation)

set(TIMESPAN_SOURCE_FILES TimespanTest.cpp)
add_executable(TimespanTest ${TIMESPAN_SOURCE_FILES})
target_link_libraries(TimespanTest PocoFoundation)

set(DATETIMEANDTIMESPAN_SOURCE_FILES DateTimeAndTimespanTest.cpp)
add_executable(DateTimeAndTimespanTest ${DATETIMEANDTIMESPAN_SOURCE_FILES})
target_link_libraries(DateTimeAndTimespanTest PocoFoundation)

set(TIMEZONE_SOURCE_FILES TimezoneTest.cpp)
add_executable(TimezoneTest ${TIMEZONE_SOURCE_FILES})
target_link_libraries(TimezoneTest PocoFoundation)

set(DATETIMEFORMATTER_SOURCE_FILES DateTimeFormatterTest.cpp)
add_executable(DateTimeFormatterTest ${DATETIMEFORMATTER_SOURCE_FILES})
target_link_libraries(DateTimeFormatterTest PocoFoundation)

set(DATETIMEPARSE_SOURCE_FILES DateTimeParserTest.cpp)
add_executable(DateTimeParserTest ${DATETIMEPARSE_SOURCE_FILES})
target_link_libraries(DateTimeParserTest PocoFoundation)


