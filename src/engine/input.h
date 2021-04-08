//
// Created by Diego Santos Seabra on 08/04/21.
//

#ifndef MARIO_INPUT_H
#define MARIO_INPUT_H

#include <glm/vec2.hpp>

namespace Input
{
    glm::vec2 getMousePosition();
    void setMousePosition(glm::vec2 position);
};


#endif //MARIO_INPUT_H
