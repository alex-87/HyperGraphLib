file(GLOB psrce *.cpp)

add_executable(demo ${psrce})
target_link_libraries (demo hypergraph)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(demo ${Boost_LIBRARIES})
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ${OpenMP_CXX_FLAGS}")
endif()

