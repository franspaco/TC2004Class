cmake_minimum_required(VERSION 3.6)
project(PrimerParcial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Inventario.h Videojuego.h)
add_executable(PrimerParcial ${SOURCE_FILES})