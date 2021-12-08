#include <iostream>
#include "dealer.h"
#include "round.h"

int main() {
    initCardValues();
    auto round = Round();

    auto dealer = new Dealer();
    auto ethan = new Player("Ethan");
    auto john = new Player("John");

    round.joinDealer(dealer);
    round.joinPlayers(2, ethan, john);

    round.go();
}
