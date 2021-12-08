#include "dealer.h"

Dealer::Dealer() {
    getNewDeck();
}

void Dealer::hit() {
    hand.add_card(deck.getACard());
}

int Dealer::sumOfHand() {
    return hand.sum();
}

Action Dealer::chooseAction() {
    return hand.sum() <= 16 ? Hit : Stand;
}

void Dealer::getNewDeck() {
    deck = Deck();
}

Deck* Dealer::getDeck() {
    return &deck;
}

Dealer::~Dealer() = default;
