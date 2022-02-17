cmake_minimum_required(VERSION 3.21)
project(novel_project C)

set(CMAKE_C_STANDARD 99)

add_executable(novel_project main.c src/headers/list_function.h src/list_function.c src/headers/project.h src/headers/reader.h src/reader.c src/headers/workflow.h src/workflow.c src/headers/list_swap.h src/list_swap.c src/headers/input.h src/input.c src/headers/writer.h src/writer.c src/headers/enums.h src/enums.c src/output.c src/headers/output.h src/crypt.c src/headers/crypt.h src/string.c src/headers/string.h src/headers/list.h src/list_sort.c src/headers/list_sort.h)