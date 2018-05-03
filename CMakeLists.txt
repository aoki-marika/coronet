# CMake minimum version
cmake_minimum_required(VERSION 2.6)

# C++ 17
set(CMAKE_CXX_STANDARD 17)

# Set custom CMake module files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find and include SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

# Find and include PhysicsFS
find_package(PhysFS REQUIRED)

include_directories(${PHYSFS_INCLUDE_DIR})

# Include sub-projects
add_subdirectory(Coronet)
add_subdirectory(Tests)