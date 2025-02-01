cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# including the direcotry
include_directories(models)


add_executable(${PROJECT_NAME} main.cpp models/RubiksCube.cpp models/3DArrayModel.cpp)
