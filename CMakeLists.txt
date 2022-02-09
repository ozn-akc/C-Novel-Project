cmake_minimum_required(VERSION 3.21)
project(novel_project C)

set(CMAKE_C_STANDARD 99)

add_executable(novel_project main.c src/headers/novel_list.h src/novel_list.c src/headers/project.h src/headers/reader.h src/reader.c src/headers/workflow.h src/workflow.c src/headers/list_swap.h src/list_swap.c)
