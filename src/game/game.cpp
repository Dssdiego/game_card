//
// Created by Diego Santos Seabra on 26/03/21.
//

#include <glm/ext.hpp>
#include "game.h"
#include "../engine/sprite_renderer.h"
#include "../engine/resource_manager.h"
#include "../engine/sprite.h"
#include "../engine/scene.h"

//SpriteRenderer *spriteRenderer;

//Sprite *coin;
//Sprite *extraLife;

Scene testScene = Scene();

Game::Game(unsigned int width, unsigned int height) : state(ACTIVE), keys(), width(width), height(height)
{}

Game::~Game()
{

}

void Game::init()
{
//    coin = new Sprite("assets/sprites/coin.png", true);
//    extraLife = new Sprite("assets/sprites/extra_life.png", true);
}

void Game::processInput(float deltaTime)
{

}

void Game::update(float deltaTime)
{

}

void Game::render()
{
//    coin->draw(glm::vec2(200.0f,200.0f), glm::vec2(48.0f, 48.0f),
//                               0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

//    extraLife->draw(glm::vec2(250.0f, 250.0f), glm::vec2(48.0f, 48.0f), 0.0f,
//                    glm::vec3(1.0f, 1.0f, 1.0f));

//    spriteRenderer->drawSprite(ResourceManager::GetTexture("face"),
//                               glm::vec2(200.0f, 200.0f), glm::vec2(128.0f, 32.0f),
//                               0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    // TODO: Create transform class
}
