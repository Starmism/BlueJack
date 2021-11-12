#ifndef BLUEJACK_CARDS_H
#define BLUEJACK_CARDS_H

#pragma once

#include <unordered_map>
#include <vector>
#include <stdexcept>

enum Suit { Diamonds, Hearts, Clubs, Spades };
enum Value { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct Card {
    Suit suit;
    Value value;
};

extern std::unordered_map<Value, int> cardValues;
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
