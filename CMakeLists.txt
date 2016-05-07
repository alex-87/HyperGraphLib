cmake_minimum_required( VERSION 2.8 )

find_package( Boost 1.58 )
find_package( Boost COMPONENTS program_options REQUIRED )

set(Boost_DEBUG off)

set( CMAKE_CXX_FLAGS "-O3 -fopenmp -std=c++11" )

file(GLOB psrc ./src/*/*.cpp)
add_executable(HypergraphLib ${psrc})

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(HypergraphLib ${Boost_LIBRARIES})
endif()

