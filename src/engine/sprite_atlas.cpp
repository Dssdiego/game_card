//
// Created by Diego Santos Seabra on 07/04/21.
//

#include "sprite_atlas.h"
#include "math/vec2.h"

Sprite SpriteAtlas::getSprite(int index)
{
    return sprites[index];
}

SpriteAtlas::SpriteAtlas(const Texture2D &texture2D, int spriteWidth, int spriteHeight) : texture2D(
        texture2D), spriteWidth(spriteWidth), spriteHeight(spriteHeight)
{
    // Correção
    int texWidth = (int) texture2D.Width;
    int texHeight = (int) texture2D.Height;

    int nRows = texWidth / spriteWidth;
    int nColumns = texHeight / spriteHeight;
    int numOfSprites = nRows * nColumns;

    // We start reading the texture at the (0,0) coordinate (top-left)
    int posX = 0;
    int posY = 0;

    // sprite: 60x84
    for (int currentSprite = 0; currentSprite < numOfSprites; ++currentSprite)
    {
        Vec2 topLeft = Vec2(posX, posY);                                   // (0,0)    (0,84)
        Vec2 topRight = Vec2(posX + spriteWidth, posY);                 // (60,0)   (60,84)
        Vec2 bottomLeft = Vec2(posX, posY + spriteHeight);              // (0, 84)  (0,168)
        Vec2 bottomRight = Vec2(spriteWidth, posY + spriteHeight);      // (60,84)  (60,168)

        // FIXME: This is not a good practice. Treat origin at (0,0) bottom-left and redo the code!
        //  https://gamedev.stackexchange.com/questions/26175/how-do-i-load-a-texture-in-opengl-where-the-origin-of-the-texture0-0-isnt-in
        //  https://learnopengl.com/Getting-started/Textures
        Vec2 texTopLeft = Vec2(topLeft.x / texWidth, -topLeft.y / texHeight);
        Vec2 texTopRight = Vec2(topRight.x / texWidth, -topRight.y / texHeight);
        Vec2 texBottomLeft = Vec2(bottomLeft.x / texWidth, -bottomLeft.y / texHeight);
        Vec2 texBottomRight = Vec2(bottomRight.x / texWidth, -bottomRight.y / texHeight);

        auto sprite = Sprite(texture2D);
        sprite.texCoords[0] = texTopLeft;
        sprite.texCoords[1] = texBottomRight;
        sprite.texCoords[2] = texBottomLeft;
        sprite.texCoords[3] = texTopRight;

        // REVIEW: This should be 'automatic'
        sprite.texWidth = spriteWidth;
        sprite.texHeight = spriteHeight;

        sprites.push_back(sprite);

        // Jump to the sprite at the right
        posX += spriteWidth;

        // If we got to the end of the texture (horizontally)
        if (posX >= texWidth)
        {
            // Reset the position to 0 and jump one line (below) -> remember the (0,0) coordinate is at the top left
            posX = 0;
            posY += spriteHeight;
        }
    }







//    // Calculate current texture position
//    unsigned int currentX = 0;
//    unsigned int currentY = texture2D.Height - spriteHeight;
//
//    // Iterate over the number of sprites
//    for (int i = 0; i < numSprites; ++i)
//    {
//        // Calculate sprite texture coordinates
//        float topY = (float) (currentY + spriteHeight) / (float) texture2D.Height;
//        float rightX = (float) (currentX + spriteWidth) / (float) texture2D.Width;
//        float leftX = (float) currentX / (float) texture2D.Width;
//        float bottomY = (float) currentY / (float) texture2D.Height;
//
////        glm::vec2 texCoords[] = {
////                {leftX, topY},          // [0] top-left
////                {rightX, bottomY},      // [1] bottom-right
////                {leftX, bottomY},       // [2] bottom-left
////                {rightX, topY}          // [3] top-right
////        };
//
//        // Primeiro sprite
////        glm::vec2 texCoords[] = {
////                {0.0f, 0.25f},
////                {1.0f, 0.0f},
////                { 0.0f, 0.0f},
////                { 1.0f, 0.25f}
////        };
//
//        // segundo sprite
//        glm::vec2 texCoords[] = {
//                {0.0f, 0.5f},
//                {1.0f, 0.25f},
//                { 0.0f, 0.25f},
//                { 1.0f, 0.5f}
//        };
//
////        float tw = (float) spriteWidth / (float) texture2D.Width;
////        float th = (float) spriteHeight / (float) texture2D.Height;
////        int numPerRow = texture2D.Width / spriteWidth;
////        float tx = (float) (i % numPerRow) * tw;
////        float ty = (float) (i / numPerRow + 1) * th;
//
////        glm::vec2 texCoords[] = {
////                {tx, ty},
////                {tx + tw, ty},
////                {tx + tw, ty + th},
////                {tx, ty + th}
////        };
//
////        glm::vec2 texCoords[] = {
////                {tx, ty},
////                {tw, tx},
////                {tx, tx},
////                {tw, ty}
////        };
//
//        // Add sprite to the list
//        auto sprite = Sprite(texture2D);
//        sprite.texCoords[0] = texCoords[0];
//        sprite.texCoords[1] = texCoords[1];
//        sprite.texCoords[2] = texCoords[2];
//        sprite.texCoords[3] = texCoords[3];
//
//        // REVIEW: This should be 'automatic'
//        sprite.texWidth = spriteWidth;
//        sprite.texHeight = spriteHeight;
//
//        sprites.push_back(sprite);
//
//        // Move current position until the end of the atlas
////        currentX += spriteWidth;
////        if (currentX >= texture2D.Width)
////        {
////            // We got to the end (horizontal) of the image
////            // So we reset the X and "jump" to the next "line"
////            currentX = 0;
////            currentY -= texture2D.Height;
////        }
//    }
}



