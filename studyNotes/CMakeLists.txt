include_directories(.)

cmake_minimum_required(VERSION 3.17)
project(studyNotes)

set(CMAKE_CXX_STANDARD 20)

add_executable(studyNotes courseProject/funcTemplate.cpp classTempProj/main.cpp)
ADD_SUBDIRECTORY(courseTutorial)
ADD_SUBDIRECTORY(classTempProj)

