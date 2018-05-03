# Coronet project
cmake_minimum_required(VERSION 2.6)
project(Coronet)

# Include source files
file(GLOB Coronet_src "src/*.cpp" "include/Coronet/*.hpp")
include_directories(include include/Coronet src)

# Create library
add_library(Coronet ${Coronet_src})
target_include_directories(Coronet PUBLIC include)

# Zip up assets
file(GLOB Coronet_assets "assets/Images/*.png" "assets/Fonts/*.ttf")
add_custom_target(Coronet.Assets ALL DEPENDS COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Coronet.assets.zip" --format=zip
        ${Coronet_assets})

# Link dependencies
target_link_libraries(Coronet ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${PHYSFS_LIBRARY})