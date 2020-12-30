include_directories(.)

cmake_minimum_required(VERSION 3.17)
project(courseTutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(courseTutorial main.cpp person.hpp person.cpp)
