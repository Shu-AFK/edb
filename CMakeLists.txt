cmake_minimum_required(VERSION 3.10)

project(edb LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -O2)

add_executable(edb
    main.cpp
    dbg/debugger.cpp
    dbg/debugger.h 
    dbg/helper.h
    extern/linenoise/linenoise.c
)

target_include_directories(edb PRIVATE dbg)
target_include_directories(edb PRIVATE extern/linenoise)
