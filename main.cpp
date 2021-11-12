#include <iostream>
#include "dealer.h"

int main() {
    initCardValues();
    auto dealer = std::make_unique<Dealer>();

    dealer->hit();
    dealer->hit();
    dealer->hitPlayers();
    dealer->hitPlayers();

    while (true) {
        for (auto& player : *dealer->getPlayers()) {
            auto action = player->chooseAction();
            if (action == Hit) {
                player->hit(dealer->getDeck()->getACard(), true);
            } else if (action == Stand) {
                continue;
            } else {
                // TODO: Add splitting logic
                continue;
            }
        }

        break;
    }
}
