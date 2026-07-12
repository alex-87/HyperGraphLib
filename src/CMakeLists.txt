file(GLOB psrc */*.cpp)

add_library(hypergraph SHARED ${psrc})

install (TARGETS hypergraph DESTINATION lib)
install (DIRECTORY "${PROJECT_BINARY_DIR}/include/Hypergraph"        
         DESTINATION include)

include_directories(${GECODE_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(hypergraph ${GECODE_LIBRARIES})

