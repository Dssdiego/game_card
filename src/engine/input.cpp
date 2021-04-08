//
// Created by Diego Santos Seabra on 08/04/21.
//

#include "input.h"

glm::vec2 mousePosition;

glm::vec2 Input::getMousePosition()
{
    return mousePosition;
}

void Input::setMousePosition(glm::vec2 position)
{
    mousePosition = position;
}
