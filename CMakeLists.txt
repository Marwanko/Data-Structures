cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(project main.cpp User.cpp friends.cpp User.h friends.h)