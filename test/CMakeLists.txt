add_executable(test_model test.cpp)
add_executable(test_algorithm test_algorithm.cpp)
add_executable(test_io test_io.cpp)

target_link_libraries(test_model hypergraph)
target_link_libraries(test_algorithm hypergraph)
target_link_libraries(test_io hypergraph)

include_directories(${GECODE_INCLUDE_DIR})
target_link_libraries(test_model ${GECODE_LIBRARIES})
target_link_libraries(test_algorithm ${GECODE_LIBRARIES})
target_link_libraries(test_io ${GECODE_LIBRARIES})

add_test(NAME Model_creation COMMAND test_model)
add_test(NAME Algorithm_results COMMAND test_algorithm)
add_test(NAME IO_Tests COMMAND test_io)
