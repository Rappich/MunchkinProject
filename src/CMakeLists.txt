cmake_minimum_required(VERSION 3.28)
project(Munchkin_main VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")


file(GLOB_RECURSE files ./*.cpp)

# Uncomment the following lines if SQLite3 is required
# find_package(SQLite3 REQUIRED)

# No need to add_executable here, it's already done in the root CMakeLists.txt
# target_include_directories and target_link_libraries should be done in the root CMakeLists.txt if needed