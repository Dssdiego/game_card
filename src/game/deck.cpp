//
// Created by Diego Santos Seabra on 09/04/21.
//

#include "deck.h"
#include "../engine/resource_manager.h"

void Deck::createCards()
{
    Card c1 = Card(Sprite(ResourceManager::GetTexture("")), Suit::Clubs, 1);
}
