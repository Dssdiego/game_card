//
// Created by Diego Santos Seabra on 25/04/21.
//

#include "card_pile.h"

CardPile::CardPile()
{
}

CardPile::~CardPile()
{
}

void CardPile::render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas)
{
    for (auto & card : cards)
    {
        renderer2D->drawSprite(cardAtlas->getSprite(card.atlasIndex), card.position);
    }
}

void CardPile::addCard(Card card)
{
    card.position = lastCardPosition;
    cards.push_back(card);
    lastCardPosition = {lastCardPosition.x, lastCardPosition.y + verticalSpacing, lastCardPosition.z + 0.1f};
}

void CardPile::removeCard(const Card &card)
{
}

