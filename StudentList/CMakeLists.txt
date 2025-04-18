cmake_minimum_required(VERSION 3.31)
project(StudentList C)

set(CMAKE_C_STANDARD 11)

add_executable(StudentList main.c Item.c ListaE.c Interface.c)
