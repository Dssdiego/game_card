//
// Created by Diego Santos Seabra on 02/04/21.
//

#ifndef MARIO_STRUCTS_H
#define MARIO_STRUCTS_H

struct Vec2f
{
    float x, y;
};

struct Vec2
{
    int x, y;
};

struct Vec3f
{
    float x, y, z;
};

struct Vec3
{
    int x, y, z;
};

// Quaternion
struct Quat
{

};

struct Transform
{
    Vec3 position;
    Quat rotation;
    Vec3 scale;
};

#endif //MARIO_STRUCTS_H
