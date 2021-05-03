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
#include "engine/input.h"
#include "engine/time.h"
#include "engine/profiling/profiler.h"

// FIXME: This is duplicate in the graphics class, this is not the original
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool closeWindow = false;

Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
Config config;

int main()
{
    Instrumentor::Get().BeginSession("Mario Solitaire", "profiling.json");

    // Read configuration
    config.readFile();

    // Initialization
    Graphics::init(&config);
    Audio::init();
    game.init();

    // Hides the cursor
//    SDL_ShowCursor(SDL_DISABLE);

    // Delta Time
    Time::delta = 1.0f / 60.0f;
    uint32_t lastFrame = 0.0f;

    // Window loop
    while (!closeWindow)
    {
        // Calculate delta time
        uint32_t currentFrame = SDL_GetTicks();
        Time::delta = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Game input
        game.processInput();

        // Game update
        game.update();

        // Game render
        Graphics::clear(Color::Background);
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

            // Get mouse position
            // REVIEW: Where to put this method?
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            Input::setMousePosition(glm::vec2(mouseX, mouseY));
//            std::cout << "MouseX: " << mouseX << std::endl;
//            std::cout << "MouseY: " << mouseY << std::endl;

            // REVIEW: Might be wrong
            if (event.key.keysym.scancode >= 0)
            {
                if (event.type == SDL_KEYDOWN)
                    game.keys[event.key.keysym.scancode] = true;
                else if (event.type == SDL_KEYUP)
                    game.keys[event.key.keysym.scancode] = false;
            }
        }

        // Draw stuff on the screen (a.k.a swap the back and front buffers)
        Graphics::draw();
    }

    // Cleanup resources
    ResourceManager::Clear();
    Graphics::shutdown();
    Audio::shutdown();

    Instrumentor::Get().EndSession();

    // Closes the application
    return EXIT_SUCCESS;
}

#ifdef _WIN32
void WinMain()
{
    main();
}
#endif
