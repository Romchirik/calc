cmake_minimum_required(VERSION 3.15)
project(calc C)

set(CMAKE_C_STANDARD 99)

add_executable(calc main.c additional_functions.c additional_functions.h stack_stuff.c stack_stuff.h)