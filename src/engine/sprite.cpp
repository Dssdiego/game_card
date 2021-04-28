//
// Created by Diego Santos Seabra on 02/04/21.
//

#include "sprite.h"

Sprite::Sprite(const Texture2D &texture2D) : texture2D(texture2D)
{}

Sprite::~Sprite()
{}

//glm::mat4 &Sprite::getModel()
//{
//    if (dirty)
//    {
//        // Scale -> rotate -> translate
//        model = glm::mat4();
//        // Translate last
//        model = glm::translate(model, position);
//    }
//    return model;
//}

