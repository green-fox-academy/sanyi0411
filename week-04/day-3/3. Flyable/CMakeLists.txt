cmake_minimum_required(VERSION 3.13)
project(3__Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(3__Flyable main.cpp Flyable.cpp Vehicle.cpp Animal.cpp Bird.cpp Helicopter.cpp)