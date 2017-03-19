cmake_minimum_required( VERSION 2.8 )

project(HYPERGRAPHLIB)

find_package( Boost 1.54 )
find_package( Boost COMPONENTS program_options REQUIRED )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

find_package(Gecode REQUIRED COMPONENTS kernel support int set driver flatzinc gist minimodel search)

set(Boost_DEBUG off)

set( CMAKE_CXX_FLAGS "-O3 -std=c++11" )

add_subdirectory(src)
add_subdirectory(demo)
add_subdirectory(test)


