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

    virtual ~CardPile();

    void addCard(Card card);
    void removeCard(const Card& card);
    void render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas);

    std::vector<Card> cards;
    glm::vec3 position;
    glm::vec3 lastCardPosition;
private:
    float verticalSpacing = 24.0f;
};


#endif //MARIO_CARD_PILE_H
