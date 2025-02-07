cmake_minimum_required(VERSION 3.28)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# including the direcotry
include_directories(
  models
  includes/rapidjson
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PISTACHE REQUIRED libpistache)


add_executable(${PROJECT_NAME} main.cpp models/RubiksCube.cpp models/3DArrayModel.cpp)
target_compile_options(RubiksCubeSolver PRIVATE -fno-stack-protector)

# Link Pistache 
target_link_libraries(${PROJECT_NAME} ${PISTACHE_LIBRARIES})
