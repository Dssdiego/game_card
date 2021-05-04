//
// Created by Diego Santos Seabra on 09/04/21.
//

#ifndef MARIO_DECK_H
#define MARIO_DECK_H

#include <map>
#include "card.h"
#include "face.h"
#include "../engine/renderer.h"
#include "../engine/sprite_atlas.h"

class Deck
{
public:
    Deck();

    void mapCards();
    void mapFaceTypes();
    void shuffleCards();

    bool hasCards();

    glm::vec3 position;
    Rect bounds;

    Card getTopCard();
    Card pullCard(); // Removes a card from the deck and returns

    void render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas);

    void update();

private:
    std::vector<Card> cards;
    std::vector<Face> faces;
    Suit getSuitEnum(std::string suit);
    FaceType getFaceTypeEnum(std::string face);

    bool canDrag = false;
};

#endif //MARIO_DECK_H
