file(GLOB psrc */*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

option(BUILD_SHARED_LIBS "Build shared library" ON)

if(BUILD_SHARED_LIBS)
  add_library(hypergraph SHARED ${psrc})
else()
  add_library(hypergraph STATIC ${psrc})
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)
target_link_libraries(hypergraph Threads::Threads)

install (TARGETS hypergraph DESTINATION lib)
install (DIRECTORY "${PROJECT_SOURCE_DIR}/include/Hypergraph"
         DESTINATION include)

include_directories(${GECODE_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)
target_link_libraries(hypergraph ${GECODE_LIBRARIES})
