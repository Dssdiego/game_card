//
// Created by Diego Santos Seabra on 09/04/21.
//

#ifndef MARIO_CARD_H
#define MARIO_CARD_H

#include <glm/glm.hpp>
#include "../engine/sprite.h"

enum Suit
{
    Clubs,      // ♣
    Diamonds,   // ♦
    Hearts,     // ♥
    Spades      // ♠
};

class Card
{
public:
    Card(const Sprite &sprite, Suit suit, int value);

private:
    glm::vec2 position;
    Sprite sprite;
    Suit suit;
    int value; // Ranges from 1 to 10
};


#endif //MARIO_CARD_H
