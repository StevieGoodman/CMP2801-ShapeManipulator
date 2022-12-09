cmake_minimum_required(VERSION 3.23)
project(Assessment_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assessment_2 main.cpp src/misc/command/command.cpp src/misc/command/command.h src/misc/input/input.cpp src/misc/input/input.h src/shapes/shape/shape.cpp src/shapes/shape/shape.h src/shapes/point/point.cpp src/shapes/point/point.h src/shapes/movable/movable.cpp src/shapes/movable/movable.h src/shapes/circle/circle.cpp src/shapes/circle/circle.h src/shapes/square/square.cpp src/shapes/square/square.h src/shapes/rectangle/rectangle.cpp src/shapes/rectangle/rectangle.h)
