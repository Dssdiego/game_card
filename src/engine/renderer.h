//
// Created by Diego Santos Seabra on 06/04/21.
//

#ifndef MARIO_RENDERER_H
#define MARIO_RENDERER_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "texture.h"
#include "shader.h"
#include "color.h"
#include "sprite.h"

class Renderer2D
{
public:
    Renderer2D();
    ~Renderer2D();

    void drawQuad(glm::vec2 position, glm::vec2 size, Color color = Color::White);
    void drawCursor(glm::vec2 position, glm::vec2 size, Color color = Color::White);;
    void drawBoundingBox(glm::vec2 position, glm::vec2 size, Color color = Color::White);;
//    void drawSprite(Sprite sprite, glm::vec2 position, glm::vec2 size, Color color = Color::White);
    void drawSprite(const Sprite& sprite, glm::vec3 position, float scale = 1.0f, Color color = Color::White);
    void drawSprite(Texture2D texture2D, glm::vec2 position, glm::vec2 size, Color color = Color::White);
private:
    Shader shader;
    unsigned int quadVAO;
};


#endif //MARIO_RENDERER_H
