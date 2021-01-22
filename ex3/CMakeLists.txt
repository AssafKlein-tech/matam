
cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 11)


set(MTM_FLAGS_DEBUG "g++ -std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

#set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

find_library(DATE date ./provided)

add_executable(progC provided/test_partC.cpp partA/date_wrap.cpp partB/base_event.cpp partB/open_event.cpp partB/closed_event.cpp partB/base_event.h partB/open_event.h partB/closed_event.h partB/custom_event.h partB/generic_linked_list.h partB/event_container.cpp partB/event_container.h partB/recurring_event.h partB/festival.cpp partB/festival.h partB/custom_event.h partC/schedule.cpp partC/schedule.h)
target_link_libraries(progC ${DATE})
include_directories(progC partC partB partA provided)


add_executable(progB1 provided/test_partB.cpp partA/date_wrap.cpp partB/base_event.cpp partB/open_event.cpp partB/closed_event.cpp partB/base_event.h partB/open_event.h partB/closed_event.h partB/custom_event.h partB/generic_linked_list.h partB/event_container.cpp partB/event_container.h partB/recurring_event.h partB/festival.cpp partB/festival.h partB/custom_event.h)
target_link_libraries(progB1 ${DATE})
include_directories(progB1 partB partA provided)

#partB/one_time_event.h partB/custom_event.h partB/generic_linked_list.h 
#add_library(date date.c date.h)
add_executable(progA partA/date_wrap.cpp provided/test_partA.cpp)
target_link_libraries(progA ${DATE})
include_directories(progA partA provided)
