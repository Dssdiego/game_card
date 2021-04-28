//
// Created by Diego Santos Seabra on 24/04/21.
//

#include "foundation_pile.h"

FoundationPile::FoundationPile()
{}

bool FoundationPile::hasCards()
{
    return !cards.empty();
}

void FoundationPile::render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas)
{
//    if(this->hasCards())
//        renderer2D->drawSprite(cardAtlas->getSprite());
//    else
    renderer2D->drawSprite(cardAtlas->getSprite(56), this->position);
}
