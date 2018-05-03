# Tests project
cmake_minimum_required(VERSION 2.6)
project(Tests)

# Include source files
file(GLOB Tests_src "src/*.cpp" "include/Tests/*.hpp")
include_directories(include include/Tests src)

# Create executable
add_executable(Tests ${Tests_src})

# Zip up assets
file(GLOB Tests_assets "assets/Images/*.png")
add_custom_target(Tests.Assets ALL DEPENDS COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Tests.assets.zip" --format=zip
        ${Tests_assets})

# Link dependencies
target_link_libraries(Tests Coronet)