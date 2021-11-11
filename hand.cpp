#include "hand.h"

Hand::Hand() = default;

void Hand::add_card(Card card) {
    cards.push_back(card);
}

void Hand::clear_hand() {
    cards.clear();
}

int Hand::sum() {
    auto totalValue = 0;
    for (const auto& card: cards) {
        auto value = cardValues.at(card.value);
        if (value != -1) {
            totalValue += value;
        } else {
            if (totalValue + 11 > 21) {
                totalValue += 1;
            } else {
                totalValue += 11;
            }
        }
    }
    return totalValue;
}

Hand::~Hand() = default;
