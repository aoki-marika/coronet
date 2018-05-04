# Coronet project
cmake_minimum_required(VERSION 2.6)
project(Coronet)

# C++ 17
set(CMAKE_CXX_STANDARD 17)

# Set custom CMake module files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Include source files
file(GLOB Coronet_src "src/*.cpp" "include/Coronet/*.hpp")
include_directories(include include/Coronet src)

# Create library
add_library(Coronet ${Coronet_src})
target_include_directories(Coronet PUBLIC include)

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

# Zip up assets
file(GLOB Coronet_assets "assets/Images/*.png" "assets/Fonts/*.ttf")
add_custom_target(Coronet.Assets ALL DEPENDS COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Coronet.assets.zip" --format=zip
        ${Coronet_assets})

# Link dependencies
target_link_libraries(Coronet ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${PHYSFS_LIBRARY})