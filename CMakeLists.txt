cmake_minimum_required( VERSION 3.28 )

project(HYPERGRAPHLIB)

set( CMAKE_CXX_FLAGS "-O3 -std=c++17" )
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

find_package(Gecode REQUIRED COMPONENTS kernel support int minimodel search)

enable_testing()

add_subdirectory(src)
add_subdirectory(demo)
add_subdirectory(test)
