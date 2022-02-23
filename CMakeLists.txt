cmake_minimum_required(VERSION 3.15)

project(tolc-demo LANGUAGES CXX)

add_library(MyCppLib src/Demo/demo.cpp)
target_include_directories(MyCppLib PUBLIC include)

set_target_properties(
  MyCppLib
  PROPERTIES CXX_STANDARD 14
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)

# Can be ["latest", "v1.2.0", ...]
set(tolc_version latest)
include(FetchContent)
FetchContent_Declare(
  tolc_entry
  URL https://github.com/Tolc-Software/tolc/releases/download/${tolc_version}/tolc-${CMAKE_HOST_SYSTEM_NAME}.tar.xz
)
FetchContent_Populate(tolc_entry)

find_package(tolc CONFIG PATHS ${tolc_entry_SOURCE_DIR} REQUIRED)

# Creates a CMake target MyCppLib_python that can be
# imported and used from python as 'import MyCppLib'
tolc_create_translation(
  # Target to translate from
  # Uses PUBLIC include directories to find headers
  TARGET
  MyCppLib
  # Language to target
  LANGUAGE
  python
  # Where to put the bindings (here pybind11)
  OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/python-bindings)
