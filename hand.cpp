#include "hand.h"

Hand::Hand() = default;

bool greaterComparator(Card a, Card b) {
    return cardValues.at(a.value) > cardValues.at(b.value);
}

void Hand::add_card(Card card) {
    cards.push_back(card);
}

void Hand::clear_hand() {
    cards.clear();
}

int Hand::sum() {
    int totalValue = 0;
    sort(cards.begin(), cards.end(), &greaterComparator);
    for (const auto& card: cards) {
        int value = cardValues.at(card.value);
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
