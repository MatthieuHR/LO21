cmake_minimum_required(VERSION 3.26)
project(LO21 C)

set(CMAKE_C_STANDARD 11)

add_executable(LO21 main.c
        src/list.c
        include/list.h)
