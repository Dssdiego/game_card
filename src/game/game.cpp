//
// Created by Diego Santos Seabra on 26/03/21.
//

#include <iostream>
#include "game.h"
#include "../engine/resource_manager.h"
#include "../engine/scene.h"
#include "../engine/renderer.h"
#include "../engine/sprite_atlas.h"
#include "../engine/input.h"

Renderer2D *renderer2D;

SpriteAtlas marioAtlas;
SpriteAtlas effectsAtlas;
SpriteAtlas objectsAtlas;

SpriteAtlas cardAtlas;

int marioAnimIdx = 1;
int coinAnimIdx = 8;
int blockAnimIdx = 4;

//Scene testScene = Scene();

Game::Game(unsigned int width, unsigned int height) : state(ACTIVE), keys(), width(width), height(height)
{}

Game::~Game()
{

}

void Game::init()
{
    ResourceManager::LoadTexture("assets/sprites/square_white.png", true, "square_white");
    ResourceManager::LoadTexture("assets/cursors/cursor_hand.png", true, "cursor_hand");
//    ResourceManager::LoadTexture("assets/atlas/mario_atlas.png", true, "mario_atlas");
//    ResourceManager::LoadTexture("assets/atlas/atlas_test.png", true, "atlas_test");

//    marioAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_mario.png"),
//                             16, 32);

//    effectsAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_effects.png"),
//                               16, 16);

//    objectsAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_objects.png"),
//                               16, 16);

    cardAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_test.png"),
                            60, 84);

    renderer2D = new Renderer2D();
//    coin = new Sprite("assets/sprites/coin.png", true);
//    extraLife = new Sprite("assets/sprites/extra_life.png", true);
}

void Game::processInput(float deltaTime)
{

}

void Game::update(float deltaTime)
{
//    std::cout << "DT: " << deltaTime << std::endl;
    // NOTE: Animation tests. It should render sprites at a fixed timestep
//    if ((int) deltaTime % 6 == 0)
//    {
        // Mario running
        marioAnimIdx += 1;
        if (marioAnimIdx > 2)
            marioAnimIdx = 1;

        // Coin spin
        coinAnimIdx += 1;
        if (coinAnimIdx > 11)
            coinAnimIdx = 8;

        // Block kick
        blockAnimIdx += 1;
        if (blockAnimIdx > 7)
            blockAnimIdx = 4;
//    }
}

void Game::render()
{
    // FIXME: Rendering sprites from two different textures make the "second" completely black.
    //  I think this is because of the 'AcctiveTexture' flag setting on OpenGL. The way to solve this is to
    //  implement a Sprite Batch and probably making a dirty flag

    // Cursor Test
//    renderer2D->drawCursor(Input::getMousePosition(), glm::vec2(32.0f, 32.0f));

    // Sprites Animation Test
//    renderer2D->drawSprite(marioAtlas.getSprite(marioAnimIdx), glm::vec2(0.0f, 0.0f), glm::vec2(48.0f, 96.0f));
//    renderer2D->drawSprite(objectsAtlas.getSprite(coinAnimIdx), glm::vec2(64.0f, 0.0f), glm::vec2(48.0f, 48.0f));
//    renderer2D->drawSprite(objectsAtlas.getSprite(blockAnimIdx), glm::vec2(128.0f, 0.0f), glm::vec2(48.0f, 48.0f));

    // Cards
    renderer2D->drawSprite(cardAtlas.getSprite(0), glm::vec2(0.0f, 0.0f), 1.0f);
    renderer2D->drawSprite(cardAtlas.getSprite(1), glm::vec2(100.0f, 0.0f), 1.0f);
    renderer2D->drawSprite(cardAtlas.getSprite(2), glm::vec2(200.0f, 0.0f), 1.0f);
    renderer2D->drawSprite(cardAtlas.getSprite(3), glm::vec2(300.0f, 0.0f), 1.0f);

//    renderer2D->drawQuad(glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f), Color::Cyan);
//    renderer2D->drawSprite(ResourceManager::GetTexture("mario_atlas"), glm::vec2(0.0f, 0.0f), glm::vec2(544.0f, 416.0f));
}
