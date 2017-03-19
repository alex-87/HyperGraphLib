file(GLOB psrc */*.cpp)

add_library(hypergraph SHARED ${psrc})

install (TARGETS hypergraph DESTINATION lib)
install (DIRECTORY "${PROJECT_BINARY_DIR}/include/Hypergraph"        
         DESTINATION include)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(hypergraph ${Boost_LIBRARIES})
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(${GECODE_INCLUDE_DIR})
target_link_libraries(hypergraph ${GECODE_LIBRARIES})

