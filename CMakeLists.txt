cmake_minimum_required(VERSION 3.20)
project(student_manage_project C)

set(CMAKE_C_STANDARD 11)

add_executable(student_manage_project main.c student_manager.c student_manager.h linklist.c linklist.h)
