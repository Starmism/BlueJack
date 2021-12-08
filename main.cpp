#include "dealer.h"
#include "round.h"

int main() {
    initCardValues();
    auto round = Round();

    auto dealer = Dealer();
    auto ethan = Player("Ethan");
    auto john = Player("John");

    round.joinDealer(&dealer);
    round.joinPlayers(2, &ethan, &john);

    round.go();
}
