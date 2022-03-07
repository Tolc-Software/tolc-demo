cmake_minimum_required(VERSION 3.15)

project(tolc-live LANGUAGES CXX)

add_library(MyCppLib INTERFACE)
target_include_directories(MyCppLib INTERFACE include)

set_target_properties(
  MyCppLib
  PROPERTIES INTERFACE_CXX_STANDARD 17
             INTERFACE_CXX_STANDARD_REQUIRED ON
             INTERFACE_CXX_EXTENSIONS OFF)

# Can be ["latest", "v0.2.0", ...]
set(tolc_version latest)
include(FetchContent)
FetchContent_Declare(
  tolc_entry
  URL https://github.com/Tolc-Software/tolc/releases/download/${tolc_version}/tolc-${CMAKE_HOST_SYSTEM_NAME}.tar.xz
)
FetchContent_Populate(tolc_entry)
set(tolc_DIR ${tolc_entry_SOURCE_DIR}/lib/cmake/tolc)
find_package(tolc CONFIG REQUIRED)

if(NOT language)
  message(
    FATAL_ERROR
      "Need to provid a language when configuring as: -Dlanguage=python")
endif()

# Creates a CMake target MyCppLib_${language}
tolc_create_bindings(
  # Target to translate from
  TARGET
  MyCppLib
  # Language to target
  LANGUAGE
  ${language}
  # Where to put the bindings
  OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/${language}-bindings)

# Get the built files
if(language STREQUAL python)
  set(output_files $<TARGET_FILE:MyCppLib_python>)
elseif(language STREQUAL wasm)
  set(output_files $<TARGET_FILE_DIR:MyCppLib_wasm>/MyCppLib.js
                   $<TARGET_FILE_DIR:MyCppLib_wasm>/MyCppLib.wasm)
endif()

# Copy the built lib to the ${language} directory
add_custom_command(
  TARGET MyCppLib_${language}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${output_files}
          ${CMAKE_CURRENT_LIST_DIR}/${language})
