#ifndef BLUEJACK_ROUND_H
#define BLUEJACK_ROUND_H

#include <map>
#include "player.h"
#include "dealer.h"

class Round {
private:
    std::map<Player*, double> bets;
    Dealer* dealer;
public:
    void bet (Player*, double);
    double bust (Player*);
    double get (Player*);
    void go ();
    Round (Dealer* dealer);
    ~Round ();
};


#endif //BLUEJACK_ROUND_H
