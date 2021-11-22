#ifndef BLUEJACK_PLAYER_H
#define BLUEJACK_PLAYER_H

#include <utility>
#include "hand.h"
#include <memory>

enum Action { Hit, Stand, Split };

class Player {
    std::pair<std::unique_ptr<Hand>, std::unique_ptr<Hand>> hands;
    double blues;
    std::string name;
public:
    std::string getName();
    double getBlues();
    void giveBlues(double);
    void deductBlues(double);
    bool hit (Card, bool);
    int sumOfHand (bool);
    Action chooseAction ();
    explicit Player (std::string);
    ~Player ();
};


#endif //BLUEJACK_PLAYER_H
