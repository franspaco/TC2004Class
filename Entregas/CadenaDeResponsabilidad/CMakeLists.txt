cmake_minimum_required(VERSION 3.6)
project(CadenaDeResponsabilidad)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DNSServer.h)
add_executable(CadenaDeResponsabilidad ${SOURCE_FILES})