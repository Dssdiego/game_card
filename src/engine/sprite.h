//
// Created by Diego Santos Seabra on 02/04/21.
//

#ifndef MARIO_SPRITE_H
#define MARIO_SPRITE_H

#include "texture.h"
#include "shader.h"
#include "math/vec2.h"

class Sprite
{
public:
    Texture2D texture2D;
    Vec2 texCoords[4];
    int texWidth;
    int texHeight;

    Sprite(const Texture2D &texture2D);
//    Sprite(const Texture2D &texture2D, int textWidth, int texHeight);
    ~Sprite();
//    Sprite(const char *fileName, bool useAlpha);
//    void draw(glm::vec2 position, float rotation, glm::vec3 color);
//    void draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color);
private:
    bool dirty;
//    glm::mat4 model;
};


#endif //MARIO_SPRITE_H
