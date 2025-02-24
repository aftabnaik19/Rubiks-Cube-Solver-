cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# including the direcotry
include_directories(
  src/models
  src/utils
  lib/rapidjson
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PISTACHE REQUIRED libpistache)


set(SOURCES
  src/main.cpp
  src/models/RubiksCube.cpp
  src/models/3DArrayModel.cpp
  src/models/1DArrayModel.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_options(RubiksCubeSolver PRIVATE -fno-stack-protector)

# Link Pistache 
target_link_libraries(${PROJECT_NAME} ${PISTACHE_LIBRARIES})
