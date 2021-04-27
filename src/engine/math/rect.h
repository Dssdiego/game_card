//
// Created by Diego Santos Seabra on 23/04/21.
//

#ifndef MARIO_RECT_H
#define MARIO_RECT_H

#include <glm/vec2.hpp>

class Rect
{
public:
    Rect();
    Rect(int width, int height);
    Rect(glm::vec2 pivotPoint, int width, int height);

    bool isInside(glm::vec2 point) const;

private:
    glm::vec2 pivotPos;
    float width, height;
};


#endif //MARIO_RECT_H
