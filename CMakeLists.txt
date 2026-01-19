cmake_minimum_required(VERSION 3.10)
project(DocHelper)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(dochelper ${SOURCES} apps/cli/main.cpp)
