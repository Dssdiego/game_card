//
// Created by Diego Santos Seabra on 07/04/21.
//

#ifndef MARIO_SPRITE_ATLAS_H
#define MARIO_SPRITE_ATLAS_H

#include <vector>
#include "texture.h"
#include "sprite.h"

class SpriteAtlas
{
public:
    SpriteAtlas() {};
    SpriteAtlas(const Texture2D &texture2D, int spriteWidth, int spriteHeight);

    ~SpriteAtlas() = default;

    Sprite getSprite(int index);
private:
    std::vector<Sprite> sprites;
    Texture2D texture2D;
    int spriteWidth;
    int spriteHeight;
};


#endif //MARIO_SPRITE_ATLAS_H
