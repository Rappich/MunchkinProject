cmake_minimum_required(VERSION 3.10)

project(Munchkin VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Munchkin ${SOURCES})

target_include_directories(Munchkin PRIVATE include)