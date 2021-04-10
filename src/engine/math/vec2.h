//
// Created by Diego Santos Seabra on 09/04/21.
//

#ifndef MARIO_VEC2_H
#define MARIO_VEC2_H

class Vec2
{
public:
    float x, y;

    Vec2(int x, int y);
    Vec2(float x, float y);
    Vec2(const Vec2 &other);
    Vec2();

    static const Vec2 Up;
    static const Vec2 Down;
    static const Vec2 Left;
    static const Vec2 Right;
    static const Vec2 Zero;
    static const Vec2 One;
};


#endif //MARIO_VEC2_H
