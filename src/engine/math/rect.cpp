//
// Created by Diego Santos Seabra on 23/04/21.
//

#include "rect.h"

Rect::Rect()
{}

Rect::Rect(int width, int height)
{

}

// FIXME: This method name may cause confusion!
bool Rect::isInside(glm::vec2 point) const
{
    // Is inside in the horizontal axis?
    if (point.x >= pivotPos.x && point.x <= (pivotPos.x + width)){
        // Is inside in the vertical axis?
        if (point.y >= pivotPos.y && point.y <= (pivotPos.y + height)) {
            return true;
        }
    }

    return false;
}

Rect::Rect(glm::vec2 pivotPos, int width, int height): pivotPos(pivotPos), width(width), height(height)
{
}

