//
// Created by Diego Santos Seabra on 24/04/21.
//

#ifndef MARIO_FOUNDATION_PILE_H
#define MARIO_FOUNDATION_PILE_H

#include <vector>
#include "card.h"
#include "../engine/renderer.h"
#include "../engine/sprite_atlas.h"

class FoundationPile
{
public:
    FoundationPile();

    void render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas);

    glm::vec3 position;
private:
    bool hasCards();

    int atlasIndex;
    std::vector<Card> cards;
};


#endif //MARIO_FOUNDATION_PILE_H
