//
// Created by Diego Santos Seabra on 09/04/21.
//

#include "deck.h"
#include "../engine/input.h"
#include <csv.h>
#include <algorithm>
#include <random>
#include <iostream>

Deck::Deck()
{}

void Deck::mapCards()
{
    io::CSVReader<4> in ("assets/csv/map_atlas_cards.csv");
    in.read_header(io::ignore_extra_column, "index", "card_name", "suit", "value");
    int index;
    std::string cardName;
    std::string suit;
    int value;
    while(in.read_row(index, cardName, suit, value)) {
        Card card = Card(index, cardName, getSuitEnum(suit), value);
        cards.push_back(card);
    }
}

void Deck::mapFaceTypes()
{
    io::CSVReader<2> in ("assets/csv/map_atlas_faces.csv");
    in.read_header(io::ignore_extra_column, "index", "face_type");
    int index;
    std::string faceType;
    while(in.read_row(index, faceType)) {
        Face face = Face(index, getFaceTypeEnum(faceType));
        faces.push_back(face);
    }
}

Suit Deck::getSuitEnum(std::string suit)
{
    if (suit == "spades")
        return Spades;

    if (suit == "diamonds")
        return Diamonds;

    if (suit == "clubs")
        return Clubs;

    if (suit == "hearts")
        return Hearts;
}

FaceType Deck::getFaceTypeEnum(std::string face)
{
    if (face == "win")
        return Win;

    if (face == "normal")
        return Normal;

    if (face == "space")
        return Space;
}

void Deck::shuffleCards()
{
    std::random_device randomDevice;
    std::mt19937 rng(randomDevice());
    std::shuffle(std::begin(cards), std::end(cards), rng);
}

bool Deck::hasCards()
{
    return !cards.empty();
}

void Deck::render(Renderer2D *renderer2D, SpriteAtlas *cardAtlas)
{
    if (this->hasCards())
        renderer2D->drawSprite(cardAtlas->getSprite(52), this->position);
}

void Deck::update()
{
    // Mouse is hovering deck, allow click
    if (bounds.isInside(Input::getMousePosition()))
        canDrag = true;

    if (canDrag)
        position = glm::vec3(Input::getMousePosition(), -1.0f);
}

Card Deck::getTopCard()
{
    return cards.front();
}

Card Deck::pullCard()
{
    // Get the last card of the vector
    Card pulledCard = cards.back();

    // Removes the card from the vector
    cards.pop_back();

    // Returns pulled card
    return pulledCard;
}

