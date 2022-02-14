cmake_minimum_required (VERSION 3.16.3)
project(Demo CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -lGL -lGLU -lglut -lm")

# add_executable(exe solar_system_demo.cpp)

add_executable(exe animation.cpp)
