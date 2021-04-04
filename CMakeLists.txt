set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.6)

# Project name
project(mario CXX)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    # use bundled version to save ourselves a lot of trouble
    set(SDL2MAIN_LIBRARY "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/libSDL2main.a")

    set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2/include/SDL2")
    set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/libSDL2.dll.a")

    set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2_image/include")
    set(SDL2_IMAGE_LIBRARIES "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/SDL2_image.lib")
    
    # copy dynamic libraries
    file(COPY 
            "${CMAKE_SOURCE_DIR}/libs/SDL2/bin/SDL2.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/libjpeg-9.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/libpng16-16.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/libtiff-5.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/libwebp-4.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/SDL2_image.dll"
            "${CMAKE_SOURCE_DIR}/libs/SDL2_image/lib/x64/zlib1.dll"
            DESTINATION ${CMAKE_BINARY_DIR})

    # Setup GLEW library
    set(GLEW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/glew/include/GL")
    set(GLEW_LIBRARY "${CMAKE_SOURCE_DIR}/libs/glew/lib/Release/x64/glew32.lib")
    file(COPY
            "${CMAKE_SOURCE_DIR}/libs/glew/bin/Release/x64/glew32.dll"
            DESTINATION ${CMAKE_BINARY_DIR})

    include_directories(${GLEW_INCLUDE_DIR})
else()
    # let FindSDL2.cmake figure out where it is on Mac/Linux
    # Put the FindSDL2.cmake in ./cmake and tell CMake to find it there
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

    set(SDL2MAIN_LIBRARY "")

    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)

    # Find OpenGL
    find_package(OpenGL REQUIRED)
    # find_package(SDL2_ttf REQUIRED)

    # Setup FMOD library
    set(FMOD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/fmod/inc")
    set(FMOD_LIBRARY
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/osx/libfmod.dylib"
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/osx/libfmodL.dylib")
    file(COPY
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/osx/libfmod.dylib"
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/osx/libfmodL.dylib"
            DESTINATION ${CMAKE_BINARY_DIR})
endif()

# Linux Configurations
if(UNIX AND NOT APPLE)
    # Setup FMOD library
    set(FMOD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/fmod/inc")
    set(FMOD_LIBRARY
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/linux/libfmod.so.12.8"
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/linux/libfmodL.so.12.8")
    file(COPY
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/linux/libfmod.so.12.8"
            "${CMAKE_SOURCE_DIR}/libs/fmod/lib/linux/libfmodL.so.12.8"
            DESTINATION ${CMAKE_BINARY_DIR})
endif()

# include SDL and OpenGL directories
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR})

# load source and header files
file(GLOB_RECURSE SOURCE_FILES
        "src/*.h"
        "src/*.cpp")
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

# include libraries
include_directories(libs/glm
                    libs/stb
                    ${FMOD_INCLUDE_DIR})

# make assets directory in build
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)

# copy game assets into build/assets directory
file(COPY
        "assets/"
        DESTINATION ${CMAKE_BINARY_DIR}/assets)

# SDL2MAIN_LIBRARY is needed for Windows specific main function.
target_link_libraries(${PROJECT_NAME}
        ${SDL2MAIN_LIBRARY}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${GLEW_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${FMOD_LIBRARY})
