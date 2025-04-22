cmake_minimum_required(VERSION 3.29)
project(Final_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Final_Project main.cpp
        Patient_Registry.cpp
        Patient_Registry.h
        System.cpp
        System.h
        Schedule.cpp
        Schedule.h)
