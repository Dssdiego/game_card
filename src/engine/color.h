//
// Created by Diego Santos Seabra on 01/04/21.
//

#ifndef MARIO_COLOR_H
#define MARIO_COLOR_H

#include <glm/vec4.hpp>
#include <string>

struct Color
{
    // Colors can only go from 0.0f to 1.0f
    float r,g,b,a;

    // Constructor
    Color(float r, float g, float b, float a);
    Color(std::string hex);

    Color();

    // Color definitions
    static const Color Transparent;
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Pink;
    static const Color Cyan;
    static const Color Background;
};


#endif //MARIO_COLOR_H
