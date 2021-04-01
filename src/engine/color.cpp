//
// Created by Diego Santos Seabra on 01/04/21.
//

#include "color.h"

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

const Color Color::Transparent = Color(0.0f,0.0f,0.0f,0.0f);
const Color Color::Black = Color(0.0f,0.0f,0.0f,1.0f);
const Color Color::White = Color(1.0f,1.0f,1.0f,1.0f);
const Color Color::Red = Color(1.0f,0.0f,0.0f,1.0f);
const Color Color::Green = Color(0.0f,1.0f,0.0f,1.0f);
const Color Color::Blue = Color(0.0f,0.0f,1.0f,1.0f);
const Color Color::Yellow = Color(1.0f,1.0f,0.0f,1.0f);
const Color Color::Pink = Color(1.0f,0.0f,1.0f,1.0f);
const Color Color::Cyan = Color(0.0f,1.0f,1.0f,1.0f);
