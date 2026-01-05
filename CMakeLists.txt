cmake_minimum_required(VERSION 4.0)
project(mai_lab_fsm C)

set(CMAKE_C_STANDARD 17)

add_executable(mai_lab_fsm
        main.c
        fsm/fsm.c
        fsm/fsm.h
        utf/utf.h
        utf/utf-16.c
        utf/utf-8.c
)
