//
// Created by Diego Santos Seabra on 25/04/21.
//

#include "card_pile.h"

CardPile::CardPile()
{}

void CardPile::render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas)
{
    renderer2D->drawSprite(cardAtlas->getSprite(0), this->position);
}

void CardPile::addCard(const Card& card)
{
    cards.push_back(card);
}
