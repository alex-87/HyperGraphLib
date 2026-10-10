file(GLOB psrce *.cpp)

add_executable(demo ${psrce})
target_link_libraries (demo hypergraph)
