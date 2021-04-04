//
// Created by Diego Santos Seabra on 02/04/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#include <glm/ext.hpp>
#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>
#include "sprite.h"
#include "resource_manager.h"
#include "graphics.h"

Sprite::Sprite(const char *fileName, bool useAlpha)
{
    // Load shader
    shader = ResourceManager::LoadShader("assets/shaders/sprite.glsl", "sprite");

    // Configure for 2D projection
    WindowSize windowSize = Graphics::getWindowSize();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(windowSize.width),
                                      static_cast<float>(windowSize.height), 0.0f,
                                      -1.0f, 1.0f);

    // Use shader
    shader
            .Use()
            .SetInteger("image", 0)
            .SetMatrix4("projection", projection);

    // Load texture
    texture2D = ResourceManager::LoadTexture(fileName, useAlpha, "");
}

void Sprite::draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color)
{
    // Prepare transformations
    shader.Use();
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    // Pass properties to the shader
    shader.SetMatrix4("model", model);
    shader.SetVector3f("spriteColor", color);

    // Bind/draw/unbind
    glActiveTexture(GL_TEXTURE0);
    texture2D.Bind();

    glBindVertexArray(Graphics::getQuadVAO());
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
