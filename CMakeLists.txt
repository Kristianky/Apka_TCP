cmake_minimum_required(VERSION 3.22)

project(Cpp_Project_Template VERSION 2.0.0 LANGUAGES C CXX)

# Pre IntelliSense – exportuje compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Apka_TCP)

