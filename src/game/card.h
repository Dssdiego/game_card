//
// Created by Diego Santos Seabra on 09/04/21.
//

#ifndef MARIO_CARD_H
#define MARIO_CARD_H

#include <glm/glm.hpp>
#include "../engine/sprite.h"
#include "../engine/math/rect.h"

/// Suit of the cards
enum Suit
{
    Clubs,      /// ♣
    Diamonds,   /// ♦
    Hearts,     /// ♥
    Spades      /// ♠
};

class Card
{
public:
//    Card(const Sprite &sprite, Suit suit, int value);
//    Card(int atlasIndex, CardValue cardValue, Suit suit, int value);
    Card(int atlasIndex, std::string cardName, Suit suit, int value);

    glm::vec3 position;
    int atlasIndex;
private:
    std::string cardName;
    Suit suit;
    Rect bounds;
    int value; /// Range (1-13), A = 1, ..., J = 11, Q = 12, K = 13
};

#endif //MARIO_CARD_H
