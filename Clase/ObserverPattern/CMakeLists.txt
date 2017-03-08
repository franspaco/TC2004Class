cmake_minimum_required(VERSION 3.6)
project(ObserverPattern)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PenaNieto.cpp PenaNieto.h DTrump.cpp DTrump.h Reforma.cpp Reforma.h Televisa.cpp Televisa.h NBCNews.cpp NBCNews.h Observer.cpp Observer.h Subject.cpp Subject.h)
add_executable(ObserverPattern ${SOURCE_FILES})