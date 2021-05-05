//
// Created by Diego Santos Seabra on 08/04/21.
//

#include "input.h"

glm::vec2 mousePosition;
bool mouseButtons[4];

glm::vec2 Input::getMousePosition()
{
    return mousePosition;
}

void Input::setMousePosition(glm::vec2 position)
{
    mousePosition = position;
}

void Input::sdlMouseButtonDown(SDL_MouseButtonEvent &event)
{
    mouseButtons[event.button] = true;
}

void Input::sdlMouseButtonUp(SDL_MouseButtonEvent &event)
{
    mouseButtons[event.button] = false;
}

bool Input::isMouseButtonPressed(MouseButton button)
{
    return mouseButtons[button];
}


