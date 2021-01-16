include_directories(.)

cmake_minimum_required(VERSION 3.17)
project(staffGovSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(staffGovSystem source/main.cpp source/workerManager.cpp header/workerManager.h source/worker.cpp header/worker.h source/employee.cpp header/employee.h source/boss.cpp header/boss.h source/manager.cpp header/manager.h source/globalFile.h)

