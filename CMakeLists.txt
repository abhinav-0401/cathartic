cmake_minimum_required(VERSION 3.24)
project(cathartic C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/include)

add_executable(cathartic
        src/include/chunk.h
        src/include/common.h
        src/include/memory.h
        src/chunk.c
        src/main.c
        src/memory.c src/include/debug.h src/debug.c src/include/value.h src/value.c)
