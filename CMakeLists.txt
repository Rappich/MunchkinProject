cmake_minimum_required(VERSION 3.28)

project(Munchkin VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Munchkin main.cpp ${SOURCES})
target_include_directories(Munchkin PRIVATE include)