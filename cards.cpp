#include <ctime>
#include "cards.h"

extern void initCardValues() {
    cardValues[Ace] = -1;
    cardValues[Two] = 2;
    cardValues[Three] = 3;
    cardValues[Four] = 4;
    cardValues[Five] = 5;
    cardValues[Six] = 6;
    cardValues[Seven] = 7;
    cardValues[Eight] = 8;
    cardValues[Nine] = 9;
    cardValues[Ten] = 10;
    cardValues[Jack] = 10;
    cardValues[Queen] = 10;
    cardValues[King] = 10;
}

Deck::Deck() {
    for (Suit suit = Diamonds; suit != Spades; ++suit) {
        for (Value value = Ace; value != King; ++value) {
            cards.push_back(Card({suit, value}));
        }
    }
}

Card Deck::getACard() {
    std::srand((unsigned) std::time(nullptr));
    int cardChoice = std::rand() % cards.size();
    auto value = cards.at(cardChoice);
    cards.erase(cards.begin() + cardChoice);
    return value;
}

bool Deck::isEmpty() {
    return cards.empty();
}

Deck::~Deck() = default;