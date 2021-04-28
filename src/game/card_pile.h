//
// Created by Diego Santos Seabra on 25/04/21.
//

#ifndef MARIO_CARD_PILE_H
#define MARIO_CARD_PILE_H

#include <vector>
#include "card.h"
#include "../engine/renderer.h"
#include "../engine/sprite_atlas.h"

class CardPile
{
public:
    CardPile();

    void addCard(const Card& card);
    void render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas);

    std::vector<Card> cards;
    glm::vec2 position;
};


#endif //MARIO_CARD_PILE_H
