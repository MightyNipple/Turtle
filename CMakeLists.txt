cmake_minimum_required (VERSION 2.9)
project (Turtle)


set(VERSION 1.0.2)


set(DO_USE_SDL true)
set(DO_USE_FLTK false)
set(DO_USE_SOFTWARE_RENDERING true)


#do not edit anything below

include_directories(include)
file(GLOB SOURCES "src/*.cpp"
                  "src/PlatformDependent/*.cpp")

if (${DO_USE_SOFTWARE_RENDERING})
    file(GLOB CPP_SR_FILES "src/PlatformDependent/SoftwareRender/*.cpp")
    file(GLOB CPP_SR_HEADERS "src/PlatformDependent/SoftwareRender/*.h")
    set(SOURCES ${SOURCES} ${CPP_SR_FILES} ${CPP_SR_HEADERS})
endif()

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


