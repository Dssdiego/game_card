//
// Created by Diego Santos Seabra on 08/04/21.
//

#ifndef MARIO_INPUT_H
#define MARIO_INPUT_H

#include <glm/vec2.hpp>
#include <SDL_events.h>

enum MouseButton
{
    NONE = 0,
    LEFT = 1,
    MIDDLE = 2,
    RIGHT = 3
};

namespace Input
{
    glm::vec2 getMousePosition();
    void setMousePosition(glm::vec2 position);

    void sdlMouseButtonDown(SDL_MouseButtonEvent &event);
    void sdlMouseButtonUp(SDL_MouseButtonEvent &event);

    // TODO: Make ability to distinguish between click and holding a MouseButton
    bool isMouseButtonPressed(MouseButton button);
}


#endif //MARIO_INPUT_H
