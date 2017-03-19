add_executable(test_model test.cpp)
add_executable(test_algorithm test_algorithm.cpp)
add_executable(test_io test_io.cpp)

target_link_libraries(test_model hypergraph)
target_link_libraries(test_algorithm hypergraph)
target_link_libraries(test_io hypergraph)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(test_model ${Boost_LIBRARIES})
  target_link_libraries(test_algorithm ${Boost_LIBRARIES})
  target_link_libraries(test_io ${Boost_LIBRARIES})
endif()

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(${GECODE_INCLUDE_DIR})
target_link_libraries(test_model ${GECODE_LIBRARIES})
target_link_libraries(test_algorithm ${GECODE_LIBRARIES})
target_link_libraries(test_io ${GECODE_LIBRARIES})

target_link_libraries(test_model criterion)
target_link_libraries(test_algorithm criterion)
target_link_libraries(test_io criterion)

enable_testing()
add_test("Model creation" test_model)
add_test("Algorithm results" test_algorithm)
add_test("IO Tests" test_io)
