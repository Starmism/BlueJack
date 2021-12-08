#include "player.h"
#include <memory>
#include <iostream>
#include <utility>

Player::Player(std::string name) {
    hands = {
            std::make_unique<Hand>(),
            nullptr
    };
    blues = 100.0;
    this->name = std::move(name);
}

bool Player::hit(Card card, bool first) {
    if (first) {
        hands.first->add_card(card);
        return true;
    } else {
        // They're adding to the second hand, which might not exist
        if (hands.second != nullptr) {
            hands.second->add_card(card);
            return true;
        }
    }
    return false;
}

int Player::sumOfHand(bool first) {
    if (first) {
        return hands.first->sum();
    } else {
        if (hands.second != nullptr) {
            return hands.second->sum();
        }
    }
    return -1;
}

Action Player::chooseAction() {
    bool canSplit = hands.second == nullptr && hands.first->cards.size() == 2 &&
        cardValues.at(hands.first->cards.at(0).value) == cardValues.at(hands.first->cards.at(1).value);

    std::cout << "Player " + name + ", your hand is currently: ";
    for (auto& card : hands.first->cards) {
        std::cout << getCardName(card) << ", ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "Press H to hit, S to stand";
    if (canSplit) {
        std::cout << " or press P to split.";
    }
    std::cout << std::endl;
    char input = ' ';
    while (true) {
        std::cin >> input;

        switch(tolower(input)) {
            case 'h':
                return Action::Hit;
            case 's':
                return Action::Stand;
            case 'p':
                if (canSplit) {
                    return Action::Split;
                }
        }
        std::cout << "Invalid answer, try again!";
    }
}

std::string Player::getName() {
    return name;
}

double Player::getBlues() {
    return blues;
}

void Player::deductBlues(double amount) {
    std::cout << "Player " << name << " deducted " << amount << " blues." << std::endl;
    blues -= amount;
}

void Player::giveBlues(double amount) {
    std::cout << "Player " << name << " gained " << amount << " blues!" << std::endl;
    blues += amount;
}

bool Player::split() {
    return false;
}


Player::~Player() = default;
