cmake_minimum_required(VERSION 3.5)

project(MN_Lab_1)

set(CMAKE_CXX_FLAGS "${SMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")

add_executable(MN_Lab_1 ${source_files})
