#ifndef BLUEJACK_DEALER_H
#define BLUEJACK_DEALER_H

#include "player.h"

class Dealer {
private:
    Hand hand;
    Deck deck;
    void getNewDeck ();
public:
    void hit ();
    int sumOfHand ();
    Action chooseAction ();
    Deck* getDeck ();
    Dealer ();
    ~Dealer ();
};

#endif //BLUEJACK_DEALER_H
