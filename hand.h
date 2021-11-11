#ifndef BLUEJACK_HAND_H
#define BLUEJACK_HAND_H

#include "cards.h"

class Hand {
public:
    std::vector<Card> cards;
    void add_card (Card);
    void clear_hand ();
    int sum ();
    Hand();
    ~Hand();
};

#endif //BLUEJACK_HAND_H
