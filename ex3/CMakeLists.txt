
cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 11)


set(MTM_FLAGS_DEBUG "g++ -std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

#set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

find_library(DATE date ./provided)
<<<<<<< HEAD
include_directories(progB partB provided)
add_executable(progB provided/test_partB.cpp partB/event_container.cpp partB/event_queue.cpp partB/base_event.cpp
partB/festival.cpp partB/recurring_event.cpp)
target_link_libraries(progB ${DATE})

include_directories(progA partA provided)
add_executable(progA partA/date_wrap.cpp provided/test_partA.cpp)
target_link_libraries(progA ${DATE})
=======

include_directories(progB provided partB)
add_executable(progB provided/test_partB.cpp partB/event_container.cpp partB/base_event.cpp partB/festival.cpp)
target_link_libraries(progB ${DATE})
>>>>>>> bce1169b88b6d3dbdb7ba1504b46e131a04fd5b5

include_directories(progA partA provided)
add_executable(progA partA/date_wrap.cpp provided/test_partA.cpp)
target_link_libraries(progA ${DATE})


