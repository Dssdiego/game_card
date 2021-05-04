//
// Created by Diego Santos Seabra on 25/04/21.
//

#include "card_pile.h"

CardPile::CardPile()
{}

CardPile::~CardPile()
{
}

void CardPile::render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas)
{
//    for (int i = 0; i < cards.size(); ++i)
//    {
//
//    }

    renderer2D->drawSprite(cardAtlas->getSprite(0), this->position);
}

void CardPile::addCard(const Card& card)
{
    cards.push_back(card);
}

void CardPile::removeCard(const Card &card)
{
    // TODO: Implement
//    cards.
}

