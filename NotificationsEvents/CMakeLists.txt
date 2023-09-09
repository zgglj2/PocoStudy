cmake_minimum_required(VERSION 2.8)
project(NotificationsEvents)

include(../CMakeDepend.txt)

set(SOURCE_FILES NotificationCenterTest.cpp)
add_executable(NotificationCenterTest ${SOURCE_FILES})
target_link_libraries(NotificationCenterTest PocoFoundation)

set(SOURCE_FILES NotificationQueueTest.cpp)
add_executable(NotificationQueueTest ${SOURCE_FILES})
target_link_libraries(NotificationQueueTest PocoFoundation)

set(SOURCE_FILES EventsTest.cpp)
add_executable(EventsTest ${SOURCE_FILES})
target_link_libraries(EventsTest PocoFoundation)

