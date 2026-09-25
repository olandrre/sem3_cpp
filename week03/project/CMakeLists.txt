cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
project(Vec3Project)

message(INFO:\ ${Vec3Project_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Vec3Project_SOURCE_DIR}/bin)

include_directories(include/)

add_executable(Vec3Project main.cpp src/vec3.cpp src/ivec.cpp) 