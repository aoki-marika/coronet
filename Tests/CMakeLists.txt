# Tests project
cmake_minimum_required(VERSION 2.6)
project(Tests)

# Include source files
file(GLOB Tests_src "src/*.cpp" "include/Tests/*.hpp")
include_directories(include include/Tests src)

# Create executable
add_executable(Tests ${Tests_src})

# Link dependencies
target_link_libraries(Tests Coronet)