//
// Created by Diego Santos Seabra on 09/04/21.
//

#include "vec2.h"

Vec2::Vec2(float x, float y) : x(x), y(y)
{}

Vec2::Vec2(int x, int y) :
        x(static_cast<float>(x)),
        y(static_cast<float>(y))
{}

Vec2::Vec2(const Vec2 &other)
{
    x = other.x;
    y = other.y;
}

Vec2::Vec2() : x(0), y(0)
{}

const Vec2 Vec2::Up = Vec2(0, -1);
const Vec2 Vec2::Down = Vec2(0, 1);
const Vec2 Vec2::Left = Vec2(-1, 0);
const Vec2 Vec2::Right = Vec2(1, 0);
const Vec2 Vec2::Zero = Vec2(0, 0);
const Vec2 Vec2::One = Vec2(1, 1);

