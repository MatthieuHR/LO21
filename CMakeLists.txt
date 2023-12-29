cmake_minimum_required(VERSION 3.26)
project(LO21 C)

set(CMAKE_C_STANDARD 11)

add_executable(LO21 main.c
        src/Rules.c
        include/Rules.h
        test/TestRules.c
        src/BC.c
        include/BC.h
        src/FactList.c
        include/FactList.h
        include/define.h
        src/Properties.c
        include/Properties.h
)
