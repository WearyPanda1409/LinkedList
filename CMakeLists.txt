cmake_minimum_required(VERSION 4.3)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled LinkedList/main.c
        LinkedList/list.c
        LinkedList/list.h
        Hex8/main.c
)