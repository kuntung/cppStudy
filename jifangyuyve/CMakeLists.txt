include_directories(.)

cmake_minimum_required(VERSION 3.17)
project(jifangyuyve)

set(CMAKE_CXX_STANDARD 20)

add_executable(jifangyuyve source/main.cpp header/identity.h header/student.h source/student.cpp source/teacher.cpp header/teacher.h source/manager.cpp header/manager.h header/globalFile.h source/computerOrderSystem.cpp header/computerOrderSystem.h source/computer.cpp header/computer.h)
