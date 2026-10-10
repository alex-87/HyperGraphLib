add_executable(test_model test.cpp)
add_executable(test_algorithm test_algorithm.cpp)
add_executable(test_io test_io.cpp)

target_link_libraries(test_model hypergraph)
target_link_libraries(test_algorithm hypergraph)
target_link_libraries(test_io hypergraph)

add_test(NAME Model_creation COMMAND test_model)
add_test(NAME Algorithm_results COMMAND test_algorithm)
add_test(NAME IO_Tests COMMAND test_io)
