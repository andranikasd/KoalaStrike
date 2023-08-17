cmake_minimum_required(VERSION 3.26)
project(Lab C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(Lab
        include/logging.h
        include/network.h
        src/logging.c
        src/main.c
        src/network.c)
