file(GLOB psrce *.cpp)

add_executable(demo ${psrce})
target_link_libraries (demo hypergraph)

include_directories(${GECODE_INCLUDE_DIR})
target_link_libraries(demo ${GECODE_LIBRARIES})
