#ifndef BLUEJACK_CARDS_H
#define BLUEJACK_CARDS_H

#pragma once

#include <unordered_map>
#include <vector>
#include <stdexcept>

enum Suit { Diamonds, Hearts, Clubs, Spades };
enum Value { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

// Define the ++ operator for both suit and value so we can iterate over them
Suit& operator ++ (Suit& suit) {
    if (suit == Spades) {
        throw std::out_of_range("for Suit& operator ++ (Suit&)");
    }
    suit = Suit(static_cast<std::underlying_type<Suit>::type>(suit) + 1);
    return suit;
}

Value& operator ++ (Value& value) {
    if (value == King) {
        throw std::out_of_range("for Value& operator ++ (Value&)");
    }
    value = Value(static_cast<std::underlying_type<Value>::type>(value) + 1);
    return value;
}

struct Card {
    Suit suit;
    Value value;
};

std::unordered_map<Value, int> cardValues;
void initCardValues();

class Deck {
    std::vector<Card> cards;
public:
    Deck ();
    ~Deck ();
    Card getACard ();
    bool isEmpty ();
};

#endif //BLUEJACK_CARDS_H
