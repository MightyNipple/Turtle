cmake_minimum_required (VERSION 2.9)
project (Turtle)


set(DO_USE_SDL true)
set(DO_USE_FLTK false)


include_directories(include)
file(GLOB SOURCES "src/*.cpp" "src/PlatformDependent/*.cpp")

if (${DO_USE_SDL})
    file(GLOB CPP_SDL_FILES "src/PlatformDependent/SDL/*.cpp")
    set(SOURCES ${SOURCES} ${CPP_SDL_FILES})
elseif(${DO_USE_FLTK})
    file(GLOB CPP_FLTK_FILES "src/PlatformDependent/FLTK/*.cpp")
    set(SOURCES ${SOURCES} ${CPP_FLTK_FILES})
endif()

add_executable(Turtle ${SOURCES})

if (${DO_USE_SDL})
    FIND_PACKAGE(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
    target_link_libraries(Turtle ${SDL2_LIBRARIES})
elseif (${DO_USE_FLTK})
    FIND_PACKAGE(FLTK REQUIRED)
    include_directories(${FLTK_INCLUDE_DIRS})
    target_link_libraries(Turtle ${FLTK_LIBRARIES})
endif()



