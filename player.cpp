#include "player.h"
#include <memory>
#include <iostream>

Player::Player() {
    hands = {
            std::make_unique<Hand>(),
            nullptr
    };
    money = 100.0;
}
/**
 * Adds a card to the specified hand
 * @param card The card to add
 * @param first True for first hand, false for second hand
 * @return Boolean representing success - True for success, false for failure
 */
bool Player::hit(Card card, bool first) {
    // If they try to add a card to the first hand, put it in
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

/**
 * Returns the sum of the chosen hand
 * @param first - True for first hand, false for second hand
 * @return The sum of the value of the cards in a given hand, or -1 if the hand doesn't exist
 */
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

/**
 * This method forces the player to choose an action
 * @return One of the three Actions, depending on what they can do
 */
Action Player::chooseAction() {
    bool canSplit = hands.second == nullptr && hands.first->cards.size() == 2 &&
        cardValues.at(hands.first->cards.at(0).value) == cardValues.at(hands.first->cards.at(1).value);

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


Player::~Player() = default;
