include_directories(.)

cmake_minimum_required(VERSION 3.17)
project(yanjiangbisai)

set(CMAKE_CXX_STANDARD 20)

add_executable(yanjiangbisai main.cpp source/speechManager.cpp header/speechManager.h source/Speaker.cpp header/Speaker.h)

