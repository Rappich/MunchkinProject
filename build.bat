@echo off
REM Configure the project
cmake -B build -S .
REM Build the project using MSBuild
cmake --build . --config Debug

rem Copy the executable to the workspace directory
copy build\Debug\Munchkin.exe Munchkin.exe

rem Run the executable from the workspace directory
Munchkin.exe
