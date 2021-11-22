#include <iostream>
#include "dealer.h"
#include "round.h"

int main() {
    initCardValues();
    auto dealer = new Dealer();
    auto ethan = new Player("Ethan");
    auto john = new Player("John");
    dealer->joinPlayers(ethan);
    dealer->joinPlayers(john);

    auto round = Round(dealer);
    round.go();
}
