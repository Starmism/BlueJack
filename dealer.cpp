#include "dealer.h"

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

void Dealer::hitPlayers() {
    for (auto& player : players) {
        player->hit(deck.getACard(), true);
    }
}

Dealer::Dealer() {
    getNewDeck();
    players.push_back(std::make_unique<Player>());
}

Dealer::~Dealer() = default;

std::vector<std::unique_ptr<Player>>* Dealer::getPlayers() {
    return &players;
}

Deck* Dealer::getDeck() {
    return &deck;
}
