cmake_minimum_required(VERSION 3.27)
project(syslab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(syslab2 main.cpp
        State.cpp
        State.h
        Automaton.cpp
        Automaton.h)

set(CMAKE_EXE_LINKER_FLAGS "-static")