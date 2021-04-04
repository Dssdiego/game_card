#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION
#define SDL_MAIN_HANDLED

#ifdef _WIN32
#include <glew.h>
#else

#include <SDL_opengl.h>

#endif

#include <SDL.h>
#include "game/game.h"
#include "engine/resource_manager.h"
#include "engine/graphics.h"
#include "engine/audio.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool closeWindow = false;

Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
Config config;

int main()
{
    // Read configuration
    config.readFile();

    // Initialization
    Graphics::init(&config);
    Audio::init();
    game.init();

    // Delta Time
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // Window loop
    while (!closeWindow)
    {
        // Calculate delta time
        float currentFrame = SDL_GetTicks();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Game input
        game.processInput(deltaTime);

        // Game update
        game.update(deltaTime);

        // Game render
        Graphics::clear(Color::Pink);
        game.render();

        // Process inputs
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Close window when clicking the "X" button
            if (event.type == SDL_QUIT)
                closeWindow = true;

            // Close window when pressing escape
            if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                closeWindow = true;

            if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                Audio::playTitle();

            // REVIEW: Might be wrong
            if (event.key.keysym.scancode >= 0)
            {
                if (event.type == SDL_KEYDOWN)
                    game.keys[event.key.keysym.scancode] = true;
                else if (event.type == SDL_KEYUP)
                    game.keys[event.key.keysym.scancode] = false;
            }
        }

        Graphics::draw();
    }

    // Cleanup resources
    ResourceManager::Clear();
    Graphics::shutdown();
    Audio::shutdown();

    // Closes the application
    return EXIT_SUCCESS;
}

#ifdef _WIN32
void WinMain()
{
    main();
}
#endif
