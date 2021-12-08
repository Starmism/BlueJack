#ifndef BLUEJACK_ROUND_H
#define BLUEJACK_ROUND_H

#include <map>
#include "player.h"
#include "dealer.h"

class Round {
private:
    std::map<Player*, double> bets;
    Dealer* dealer;
    void bet (Player*, double);
    double bust (Player*);
    void hitPlayers ();
public:
    double get (Player*);
    void joinPlayers (int, ...);
    void joinDealer (Dealer*);
    void go ();
    Round ();
    ~Round ();
};


#endif //BLUEJACK_ROUND_H
