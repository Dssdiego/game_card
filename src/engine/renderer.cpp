//
// Created by Diego Santos Seabra on 06/04/21.
//

#define GL_GLEXT_PROTOTYPES
#define GL_SILENCE_DEPRECATION

#ifdef _WIN32
#include <glew.h>
#else

#include <SDL_opengl.h>
#include <SDL_opengl_glext.h>

#endif

#include "renderer.h"
#include "resource_manager.h"
#include "graphics.h"
#include "profiling/profiler.h"

Renderer2D::Renderer2D()
{
    // Configure VAO/VBO
    unsigned int vbo;

    float vertices[] = {
            // position //texture
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
    }; // (0,0) being top-left corner of the quad

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);       // bind
    glEnableVertexAttribArray(0); // (location = 0) in the shader
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_TRUE, 4 * sizeof(float), nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind
    glBindVertexArray(0);

    // Load shader
    shader = ResourceManager::LoadShader("assets/shaders/sprite.glsl", "sprite");

    // Configure for 2D projection
    WindowSize windowSize = Graphics::getWindowSize();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(windowSize.width),
                                      static_cast<float>(windowSize.height), 0.0f,
                                      -1.01f, 1.01f);

    // Use shader
    shader
            .Use()
//            .SetInteger("image", 0)
            .SetMatrix4("projection", projection);
}

Renderer2D::~Renderer2D()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}


void Renderer2D::drawQuad(glm::vec2 position, glm::vec2 size, Color color)
{
//    drawSprite(ResourceManager::GetTexture("square_white"), position, size, color);
}

void Renderer2D::drawCursor(glm::vec2 position, glm::vec2 size, Color color)
{
    drawSprite(ResourceManager::GetTexture("cursor_hand"), position, size, color);
}

void Renderer2D::drawBoundingBox(glm::vec2 position, glm::vec2 size, Color color)
{
    drawSprite(ResourceManager::GetTexture("bounding_box"), position, size, color);
}

void Renderer2D::drawSprite(Texture2D texture2D, glm::vec2 position, glm::vec2 size, Color color)
{
    InstrumentationTimer timer("Renderer2D::DrawSprite");

    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(position, 0.0f));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
//    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    // Pass properties to the shader
    this->shader.SetMatrix4("model", model);
    this->shader.SetVector3f("spriteColor", color);

    // Bind/Draw
    glActiveTexture(GL_TEXTURE0);
    texture2D.Bind();

    // Draw
    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Renderer2D::drawSprite(const Sprite& sprite, glm::vec3 position, float scale, Color color)
{
    InstrumentationTimer timer("Renderer2D::DrawSprite2");

    // Configure VAO/VBO
    unsigned int vbo;

    Vec2 texCoords[4];
    texCoords[0] = sprite.texCoords[0];
    texCoords[1] = sprite.texCoords[1];
    texCoords[2] = sprite.texCoords[2];
    texCoords[3] = sprite.texCoords[3];

    std::vector<glm::vec4> vertices;
    vertices.emplace_back(0.0f, 1.0f, texCoords[0].x, texCoords[0].y);
    vertices.emplace_back(1.0f, 0.0f, texCoords[1].x, texCoords[1].y);
    vertices.emplace_back(0.0f, 0.0f, texCoords[2].x, texCoords[2].y);
    vertices.emplace_back(0.0f, 1.0f, texCoords[0].x, texCoords[0].y);
    vertices.emplace_back(1.0f, 1.0f, texCoords[3].x, texCoords[3].y);
    vertices.emplace_back(1.0f, 0.0f, texCoords[1].x, texCoords[1].y);
//    std::reverse(vertices.begin(), vertices.end());

//    float vertices[] = {
//            // position //texture
//            // first triangle
//            0.0f, 1.0f, texCoords[0].x, texCoords[0].y, // top-left
//            1.0f, 0.0f, texCoords[1].x, texCoords[1].y, // bottom-right
//            0.0f, 0.0f, texCoords[2].x, texCoords[2].y, // bottom-left
//
//            // second triangle
//            0.0f, 1.0f, texCoords[0].x, texCoords[0].y, // top-left
//            1.0f, 1.0f, texCoords[3].x, texCoords[3].y, // top-right
//            1.0f, 0.0f, texCoords[1].x, texCoords[1].y  // bottom-right
//    }; // (0,0) being top-left corner of the quad

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(std::vector<float>), &vertices.front(), GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);       // bind
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_TRUE, 4 * sizeof(float), nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind
    glBindVertexArray(0);

    // Load shader
    shader = ResourceManager::LoadShader("assets/shaders/sprite.glsl", "sprite");

    // Configure for 2D projection
    WindowSize windowSize = Graphics::getWindowSize();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(windowSize.width),
                                      static_cast<float>(windowSize.height), 0.0f,
                                      -1.01f, 1.01f);

    // Use shader
    shader
        .Use()
        .SetMatrix4("projection", projection);

    glm::vec2 size = glm::vec2(sprite.texWidth * scale, sprite.texHeight * scale);
    glm::mat4 model = glm::mat4(1.0f);

//    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::translate(model, position);

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0f));

    // Pass properties to the shader
    this->shader.SetMatrix4("model", model);
    this->shader.SetVector3f("spriteColor", color);

    // Bind/Draw
    glActiveTexture(GL_TEXTURE0);
    sprite.texture2D.Bind();

    // Draw
    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
