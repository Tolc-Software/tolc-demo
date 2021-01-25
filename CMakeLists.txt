cmake_minimum_required(VERSION 3.15)

project(tolc-demo LANGUAGES CXX)

add_library(Math src/Demo/demo.cpp)
target_include_directories(Math PUBLIC include)

set_target_properties(Math
                      PROPERTIES
                      CXX_STANDARD
                      14
                      CXX_STANDARD_REQUIRED
                      ON
                      CXX_EXTENSIONS
                      OFF)

# Download the tolc bootstraper
include(FetchContent)
FetchContent_Declare(
  tolc_bootstrap
  GIT_REPOSITORY https://github.com/Tolc-Software/bootstrap-tolc-cmake
  GIT_TAG        main
)

FetchContent_MakeAvailable(tolc_bootstrap)
# Downloads and uses find_package to locate tolc
get_tolc()

# Creates a CMake target Math_python that can be
# imported and used from python as 'import Math'
tolc_create_translation(
  # Target to translate from
  # Uses PUBLIC include directories to find headers
  TARGET Math
  # Language to target
  LANGUAGE python
  # Where to put the bindings (here pybind11)
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/python-bindings
)
