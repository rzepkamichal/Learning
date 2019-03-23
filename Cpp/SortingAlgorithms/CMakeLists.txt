cmake_minimum_required (VERSION 3.5)

project(SortingAlgorithms)

#setting up variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14" )
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

#tell compiler what to compile
file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB header_files "${source_dir}/*.h")

#add executables
add_executable (SortingAlgorithms ${source_files} ${header_files})


