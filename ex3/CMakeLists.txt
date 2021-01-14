
cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 11)


set(MTM_FLAGS_DEBUG "g++ -std=c++11 -Wall -Werror -pedantic-errors")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

#set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

find_library(DATE date ./provided)

include_directories(progB provided partB)
add_executable(progB provided/test_partB.cpp partB/event_container.cpp partB/base_event.cpp partB/festival.cpp)
target_link_libraries(progB ${DATE})

include_directories(progA partA provided)
add_executable(progA partA/date_wrap.cpp provided/test_partA.cpp)
target_link_libraries(progA ${DATE})


