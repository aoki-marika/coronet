# Coronet project
cmake_minimum_required(VERSION 2.6)
project(Coronet)

# Include source files
file(GLOB Coronet_src "src/*.cpp" "include/Coronet/*.hpp")
include_directories(include include/Coronet src)

# Create library
add_library(Coronet ${Coronet_src})
target_include_directories(Coronet PUBLIC include)

# Link dependencies
target_link_libraries(Coronet ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})