cmake_minimum_required(VERSION 3.28)

project(HYPERGRAPHLIB)

set(CMAKE_CXX_FLAGS "-O3 -std=c++17")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

# Gecode, the constraint programming solver used by the isomorphism algorithm,
# is exposed to the other targets through the hypergraph_gecode interface target.
# More information about Gecode at https://www.gecode.dev/
option(HYPERGRAPH_FETCH_GECODE
       "Download and build Gecode ${HYPERGRAPH_GECODE_VERSION} instead of looking for an installed one" OFF)

# Gecode release to collect.
set(HYPERGRAPH_GECODE_VERSION 6.5.0)
set(HYPERGRAPH_GECODE_SHA256 83d854613d356da9bc040864479e98d81d090087366219aa23832375a965d64a)

add_library(hypergraph_gecode INTERFACE)

if(HYPERGRAPH_FETCH_GECODE)

  include(FetchContent)

  # Only the int/search/minimodel solver modules are needed.
  set(GECODE_ENABLE_QT               OFF CACHE STRING "")
  set(GECODE_ENABLE_GIST             OFF CACHE STRING "")
  set(GECODE_ENABLE_FLATZINC         OFF CACHE BOOL "")
  set(GECODE_ENABLE_EXAMPLES         OFF CACHE BOOL "")
  set(GECODE_ENABLE_CPPROFILER       OFF CACHE BOOL "")
  set(GECODE_ENABLE_DRIVER           OFF CACHE BOOL "")
  set(GECODE_ENABLE_SET_VARS         OFF CACHE BOOL "")
  set(GECODE_ENABLE_FLOAT_VARS       OFF CACHE BOOL "")
  set(GECODE_ENABLE_MPFR             OFF CACHE BOOL "")
  set(GECODE_ENABLE_CBS              OFF CACHE BOOL "")
  set(GECODE_ENABLE_AUDIT            OFF CACHE BOOL "")
  set(GECODE_ENABLE_FAULT_INJECTION  OFF CACHE BOOL "")
  set(GECODE_ENABLE_OSX_UNFAIR_MUTEX OFF CACHE BOOL "")

  # Gecode is linked statically into libhypergraph.
  set(GECODE_BUILD_SHARED OFF CACHE BOOL "")
  set(GECODE_BUILD_STATIC ON  CACHE BOOL "")
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)

  # Collecting dependency
  FetchContent_Declare(gecode
    URL https://github.com/Gecode/gecode/archive/refs/tags/release-${HYPERGRAPH_GECODE_VERSION}.tar.gz
    URL_HASH SHA256=${HYPERGRAPH_GECODE_SHA256}
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    EXCLUDE_FROM_ALL
    SYSTEM)
  FetchContent_MakeAvailable(gecode)

  target_link_libraries(hypergraph_gecode INTERFACE
    Gecode::gecodeminimodel
    Gecode::gecodesearch
    Gecode::gecodeint
    Gecode::gecodekernel
    Gecode::gecodesupport)
else()
  find_package(Gecode ${HYPERGRAPH_GECODE_VERSION} REQUIRED COMPONENTS kernel support int minimodel search)

  if(Gecode_FOUND)
    target_include_directories(hypergraph_gecode SYSTEM INTERFACE ${GECODE_INCLUDE_DIR})
    target_link_libraries(hypergraph_gecode INTERFACE ${GECODE_LIBRARIES})
  else()
    message(FATAL_ERROR
              "Gecode package ${HYPERGRAPH_GECODE_VERSION} not found. You can set -DHYPERGRAPH_FETCH_GECODE=ON"
              " to collect and build Gecode package.")
  endif()
endif()

enable_testing()

add_subdirectory(src)
add_subdirectory(demo)
add_subdirectory(test)
