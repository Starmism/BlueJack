#include <ctime>
#include "cards.h"

std::unordered_map<Value, int> cardValues;
std::unordered_map<Suit, std::string> suitNames;
std::unordered_map<Value, std::string> valueNames;

void initCardValues() {
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

    suitNames[Diamonds] = "Diamonds";
    suitNames[Hearts] = "Hearts";
    suitNames[Clubs] = "Clubs";
    suitNames[Spades] = "Spades";

    valueNames[Ace] = "Ace";
    valueNames[Two] = "Two";
    valueNames[Three] = "Three";
    valueNames[Four] = "Four";
    valueNames[Five] = "Five";
    valueNames[Six] = "Six";
    valueNames[Seven] = "Seven";
    valueNames[Eight] = "Eight";
    valueNames[Nine] = "Nine";
    valueNames[Ten] = "Ten";
    valueNames[Jack] = "Jack";
    valueNames[Queen] = "Queen";
    valueNames[King] = "King";
}

// Define the ++ operator for both suit and value, so we can iterate over them
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

std::string getCardName(Card card) {
    return valueNames[card.value] + " of " + suitNames[card.suit];
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