@echo off
rem Configure the project
cmake -S . -B build

rem Build the project
cmake --build build --config Debug

rem Change to the build directory
cd build