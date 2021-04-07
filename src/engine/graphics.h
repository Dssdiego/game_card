//
// Created by Diego Santos Seabra on 31/03/21.
//

#ifndef MARIO_GRAPHICS_H
#define MARIO_GRAPHICS_H

#include <SDL.h>
#include "color.h"
#include "config.h"

struct WindowSize
{
    int width, height;
    WindowSize(int width, int height) : width(width), height(height) {};
};

namespace Graphics
{
    void init(Config *config);

    void frame();

    // Clearing
    void clear();
    void clear(Color color);

    // Drawing
    void draw();

    // Cleanup
    void shutdown();

    // Getters
    WindowSize getWindowSize();
}


#endif //MARIO_GRAPHICS_H
