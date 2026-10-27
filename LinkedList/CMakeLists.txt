cmake_minimum_required(VERSION 3.20)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(LinkedList
        main.c
        list.c
        list.h
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(LinkedList PRIVATE -Wall -Wextra -Wpedantic)
endif()