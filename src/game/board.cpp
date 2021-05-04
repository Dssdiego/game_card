//
// Created by Diego Santos Seabra on 21/04/21.
//

#include "board.h"
#include "../engine/resource_manager.h"
#include "../engine/profiling/profiler.h"

Board::Board()
{
}

void Board::init()
{
    InstrumentationTimer timer("Board::Init");
    // Initialize Renderer
    renderer2D = new Renderer2D();

    // Load atlas
    cardAtlas = SpriteAtlas(ResourceManager::LoadTexture("assets/atlas/atlas_cards.png"),
                            cardWidth, cardHeight);

    // Deck
    deck = new Deck();
    deck->mapCards();
    deck->mapFaceTypes();
    deck->shuffleCards();
    deck->position = {32.0f, 16.0f, 0.0f};
    deck->bounds = {deck->position, cardWidth, cardHeight};

    // Foundation Piles
    // REVIEW: Change this to std::vector<CardPile> ?
    pileHearts = new FoundationPile();
    pileHearts->position = {272.0f, 16.0f, -1.0f};

    pileSpades = new FoundationPile();
    pileSpades->position = {352.0f, 16.0f, -1.0f};

    pileDiamonds = new FoundationPile();
    pileDiamonds->position = {432.0f, 16.0f, -1.0f};

    pileClubs = new FoundationPile();
    pileClubs->position = {512.0f, 16.0f, -1.0f};

    // Create Piles of Cards
    float cardPilePosition = 32.0f;
    for (int i = 0; i < 7; ++i)
    {
        auto *pile = new CardPile();
        pile->position = { cardPilePosition, 128.0f, -1.0f };
        cardPiles.emplace_back(*pile);
        cardPilePosition += cardHorizontalSpacing;
    }

// TODO: Play Draw Cards Animation
//    deck.drawCard();
}

void Board::update()
{
    InstrumentationTimer timer("Board::Update");
    deck->update();
}

void Board::render()
{
    InstrumentationTimer timer("Board::Render");
//    batch.begin();
//    deck->getTopCard();
//    batch.add(deck);
//    batch.end();

    // Deck
    deck->render(renderer2D, &cardAtlas);

    // Foundation Piles
    pileHearts->render(renderer2D, &cardAtlas);
    pileSpades->render(renderer2D, &cardAtlas);
    pileDiamonds->render(renderer2D, &cardAtlas);
    pileClubs->render(renderer2D, &cardAtlas);

    // Render Card Piles
    for (auto & cardPile : cardPiles)
    {
        cardPile.render(renderer2D, &cardAtlas);
    }
}
