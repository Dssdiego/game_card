//
// Created by Diego Santos Seabra on 31/03/21.
//

#ifndef MARIO_GRAPHICS_H
#define MARIO_GRAPHICS_H

#include <SDL.h>
#include "color.h"

namespace Graphics
{
    void init();
    void frame();
    void clear();
    void clear(Color color);
    void draw();
    void cleanup();
}


#endif //MARIO_GRAPHICS_H
