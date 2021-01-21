
cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 11)


set(MTM_FLAGS_DEBUG "g++ -std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

find_library(DATE date ./provided)

include_directories(progC ./partC ./partB ./partA ./provided)
add_executable(progC provided/test_partC.cpp partC/schedule.cpp)
target_link_libraries(progC ${DATE})


include_directories(progB ./partB ./partA ./provided)
add_executable(progB provided/test_partB.cpp partB/event_container.cpp partB/base_event.cpp partB/festival.cpp partB/recurring_event.cpp partB/open_event.cpp partB/one_time_event.h partB/custom_event.h)
target_link_libraries(progB ${DATE})

#add_library(date date.c date.h)
include_directories(progA partA provided)
add_executable(progA partA/date_wrap.cpp provided/test_partA.cpp)
target_link_libraries(progA ${DATE})
