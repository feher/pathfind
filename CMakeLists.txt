cmake_minimum_required(VERSION 3.14)
project(pathfind C)

set(CMAKE_C_STANDARD 11)

add_executable(pathfind main.c maze.c dijkstra.c maze.h dijkstra.h)