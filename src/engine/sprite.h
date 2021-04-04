//
// Created by Diego Santos Seabra on 02/04/21.
//

#ifndef MARIO_SPRITE_H
#define MARIO_SPRITE_H

#include "texture.h"
#include "shader.h"

class Sprite
{
private:
    Shader shader;
    Texture2D texture2D;
public:
    Sprite(const char *fileName, bool useAlpha);
//    void draw(glm::vec2 position, float rotation, glm::vec3 color);
    void draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color);
};


#endif //MARIO_SPRITE_H
