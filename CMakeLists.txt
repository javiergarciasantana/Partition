# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Computabilidad y Algoritmia
#
# @author Javier Garcia Santana
# @date 28 Jun 2022
# @brief CMakeLists.txt example
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(ULL_CARCEL                # Mandatory
    VERSION 1.0
    DESCRIPTION "Saquenme de la ull"
    LANGUAGES CXX)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)


# List of source files
set(SOURCES
  src/partition.cpp
)

# List of header files (not required by CMake, but for clarity/documentation)
set(HEADERS
  src/bitset.hpp
)

# Add the executable (source files only)
add_executable(Func_pr ${SOURCES})

# Optionally add header files to the target for IDEs
# This is not required but helps IDEs recognize headers as part of the project
target_sources(Func_pr PRIVATE ${HEADERS})