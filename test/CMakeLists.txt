add_executable(test_model test.cpp)
add_executable(test_algorithm test_algorithm.cpp)

target_link_libraries(test_model hypergraph)
target_link_libraries(test_algorithm hypergraph)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(test_model ${Boost_LIBRARIES})
  target_link_libraries(test_algorithm ${Boost_LIBRARIES})
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

target_link_libraries(test_model criterion)
target_link_libraries(test_algorithm criterion)

enable_testing()
add_test("Model creation" test_model)
add_test("Algorithm results" test_algorithm)
