//
// Created by Diego Santos Seabra on 01/04/21.
//

#include "color.h"

Color::Color(): r(1.0f), g(1.0f), b(1.0f), a(1.0f) {}
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
const Color Color::Background = Color(0.0f, 0.3882f, 0.0f, 1.0f);

Color::Color(std::string hex)
{
    // Remove the '#' character
    hex.erase(0, 1);

    int hexValue = std::stoi(hex);

    r = (float) ((hexValue >> 16) & 0xFF) / 255.0f;  // Extract the RR byte
    g = (float) ((hexValue >> 8) & 0xFF) / 255.0f;   // Extract the GG byte
    b = (float) ((hexValue) & 0xFF) / 255.0f;        // Extract the BB byte
    a = 1.0f;                                        // Alfa is alwaystotal
}
