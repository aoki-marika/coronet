# Coronet project
cmake_minimum_required(VERSION 2.6)
project(Coronet)

# C++ 17
set(CMAKE_CXX_STANDARD 17)

# Set output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include headers and source files
file(GLOB Coronet_src "src/*.cpp" "include/Coronet/*.hpp")
include_directories(include include/Coronet src)

# Create library
add_library(Coronet ${Coronet_src})
target_include_directories(Coronet PUBLIC include)

# Find and include SDL2
find_package(SDL2 REQUIRED)

# Link dependencies
target_link_libraries(Coronet ${SDL2_LIBRARIES})