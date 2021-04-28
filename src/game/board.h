//
// Created by Diego Santos Seabra on 21/04/21.
//

#ifndef MARIO_BOARD_H
#define MARIO_BOARD_H

#include <vector>
#include "card.h"
#include "deck.h"
#include "../engine/sprite_atlas.h"
#include "../engine/renderer.h"
#include "foundation_pile.h"
#include "card_pile.h"
#include "../engine/graphics/sprite_batch.h"

class Board
{
public:
    Board();

    void init();
    void update();
    void render();

private:
    // Dimensions
    const int cardWidth = 71;
    const int cardHeight = 96;

    // Spacings
    const float cardVerticalSpacing = 24.0f;

    // Default Positions
//    const glm::vec2 deckPosition = {32.0f, 16.0f};
//    const glm::vec2 drawPosition = {112.0f, 16.0f};

    // Variables
    SpriteBatch batch;
    SpriteAtlas cardAtlas;
    Renderer2D *renderer2D;
    Deck *deck;

    // Foundation Piles
    FoundationPile *pileDiamonds;
    FoundationPile *pileHearts;
    FoundationPile *pileClubs;
    FoundationPile *pileSpades;

    // Card piles
    CardPile *p1, *p2, *p3, *p4, *p5, *p6, *p7;
};


#endif //MARIO_BOARD_H
