//
// Created by Diego Santos Seabra on 31/03/21.
//

#include "graphics.h"

#include <SDL.h>
#include <iostream>

#ifdef _WIN32
#include <glew.h>
#else
#include <SDL_opengl.h>
#endif

SDL_Window *window;
SDL_GLContext glContext;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void Graphics::init()
{
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // Use the most recent OpenGL Version available in the machine
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
#ifdef __APPLE__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif

    // Create window
    window = SDL_CreateWindow(
            "Mario",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    // If there is any error creating the window
    if (!window)
    {
        std::cout << "Failed to create window! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    // OpenGL Context
    glContext = SDL_GL_CreateContext(window);

    // VSync
//    SDL_GL_SetSwapInterval(1);

    // Window current context
    SDL_GL_MakeCurrent(window, glContext);

    // GLEW init
#ifdef _WIN32
    GLenum glewError = glewInit();
    if(glewError != GLEW_OK)
        std::cout << "Error initializing GLEW!" << std::endl;
#endif

    // OpenGL configuration
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Print versions
    SDL_version sdlVersion;
    SDL_GetVersion(&sdlVersion);
    std::cout << "SDL Version: " << unsigned(sdlVersion.major) << "." << unsigned(sdlVersion.minor) << "."
              << unsigned(sdlVersion.patch)
              << std::endl;

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

/**
 * Clears the current framebuffer
 */
void Graphics::clear()
{
    Color color = Color::Pink;
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::clear(Color color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::draw()
{
    // Swap buffers and present to the screen
    SDL_GL_SwapWindow(window);
}

void Graphics::cleanup()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


