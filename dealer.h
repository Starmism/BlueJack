#ifndef BLUEJACK_DEALER_H
#define BLUEJACK_DEALER_H

#include "player.h"

class Dealer {
private:
    Hand hand;
    Deck deck;
    std::vector<std::unique_ptr<Player>> players;
    void getNewDeck ();
public:
    void hit ();
    int sumOfHand ();
    Action chooseAction ();
    void hitPlayers ();
    std::vector<std::unique_ptr<Player>>* getPlayers ();
    Deck* getDeck ();
    Dealer ();
    ~Dealer ();
};

#endif //BLUEJACK_DEALER_H
