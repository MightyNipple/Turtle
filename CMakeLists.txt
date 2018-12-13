cmake_minimum_required (VERSION 2.6)
project (Turtle)

include_directories(include)
link_directories(lib) 
file(GLOB SOURCES "src/*.cpp" "src/PlatformDependent/*.cpp")

add_executable(Turtle ${SOURCES})
target_link_libraries(Turtle SDL2 SDL2main)
