//
// Created by Diego Santos Seabra on 07/04/21.
//

#include "sprite_atlas.h"

Sprite SpriteAtlas::getSprite(int index)
{
    return sprites[index];
}

SpriteAtlas::SpriteAtlas(const Texture2D &texture2D, int spriteWidth, int spriteHeight, int numSprites) : texture2D(
        texture2D), spriteWidth(spriteWidth), spriteHeight(spriteHeight), numSprites(numSprites)
{
    // Calculate current texture position
    unsigned int currentX = 0;
    unsigned int currentY = texture2D.Height - spriteHeight;

    // Iterate over the number of sprites
    for (int i = 0; i < numSprites; ++i)
    {
        // Calculate sprite texture coordinates
        float topY = (float) (currentY + spriteHeight) / (float) texture2D.Height;
        float rightX = (float) (currentX + spriteWidth) / (float) texture2D.Width;
        float leftX = (float) currentX / (float) texture2D.Width;
        float bottomY = (float) currentY / (float) texture2D.Height;

//        glm::vec2 texCoords[] = {
//                {rightX, topY},
//                {rightX, bottomY},
//                {leftX, bottomY},
//                {leftX, topY}
//        };

        glm::vec2 texCoords[] = {
                {leftX, topY},          // [0] top-left
                {rightX, bottomY},      // [1] bottom-right
                {leftX, bottomY},       // [2] bottom-left
                {rightX, topY}          // [3] top-right
        };

        // Add sprite to the list
        auto sprite = Sprite(texture2D);
        sprite.texCoords[0] = texCoords[0];
        sprite.texCoords[1] = texCoords[1];
        sprite.texCoords[2] = texCoords[2];
        sprite.texCoords[3] = texCoords[3];
        sprites.push_back(sprite);

        // Move current position until the end of the atlas
        currentX += spriteWidth;
        if (currentX >= texture2D.Width)
        {
            // We got to the end (horizontal) of the image
            // So we reset the X and "jump" to the next "line"
            currentX = 0;
            currentY -= texture2D.Height;
        }
    }
}



