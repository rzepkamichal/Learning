cmake_minimum_required(VERSION 3.5)

project(interpolacja)

set(CMAKE_CXX_FLAGS "${SMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB header_files "${source_dir}/*.h")

add_executable(interpolacja ${source_files})


