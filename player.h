#ifndef BLUEJACK_PLAYER_H
#define BLUEJACK_PLAYER_H

#include <utility>
#include "hand.h"
#include <memory>

enum Action { Hit, Stand, Split };

class Player {
    std::pair<std::unique_ptr<Hand>, std::unique_ptr<Hand>> hands;
    double money;
public:
    bool hit (Card, bool);
    int sumOfHand (bool);
    Action chooseAction ();
    Player ();
    ~Player ();
};


#endif //BLUEJACK_PLAYER_H
