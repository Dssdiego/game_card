//
// Created by Diego Santos Seabra on 09/04/21.
//

#ifndef MARIO_DECK_H
#define MARIO_DECK_H

#include <vector>
#include "card.h"

class Deck
{
public:
    void createCards();
//    void shuffle();
private:
    std::vector<Card> cards;
//    int numOfCards;

};


#endif //MARIO_DECK_H
