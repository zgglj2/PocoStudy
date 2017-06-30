cmake_minimum_required(VERSION 3.6)
project(NotificationsEvents)

set(CMAKE_CXX_STANDARD 11)

include_directories("../../poco-1.7.8/Foundation/include")
link_directories("../../poco-1.7.8/cmake-build-release/lib")

set(SOURCE_FILES NotificationCenterTest.cpp)
add_executable(NotificationCenterTest ${SOURCE_FILES})
target_link_libraries(NotificationCenterTest PocoFoundation)

set(SOURCE_FILES NotificationQueueTest.cpp)
add_executable(NotificationQueueTest ${SOURCE_FILES})
target_link_libraries(NotificationQueueTest PocoFoundation)

