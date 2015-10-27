cmake_minimum_required(VERSION 3.3)
project(cavestory_clone)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCE_FILES
        src/main.cpp
        src/animatedsprite.cpp
        src/game.cpp
        src/graphics.cpp
        src/input.cpp
        src/sprite.cpp
        src/player.cpp
        src/level.cpp
        headers/animatedsprite.h
        headers/game.h
        headers/globals.h
        headers/graphics.h
        headers/input.h
        headers/sprite.h
        headers/player.h
        headers/level.h
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/headers
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
)

add_executable(
        cavestory_clone
        ${SOURCE_FILES}
)

target_link_libraries(
        cavestory_clone
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
)