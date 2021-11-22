#include <iostream>
#include "round.h"

void Round::bet(Player* player, double blues) {
    player->deductBlues(blues);
    double newBet = bets.at(player) + blues;
    bets.insert_or_assign(player, newBet);
}

double Round::bust(Player* player) {
    double bluesToBePaid = bets.at(player);
    bets.insert_or_assign(player, -1);
    return bluesToBePaid;
}

double Round::get(Player* player) {
    return bets.at(player);
}

void Round::go() {
    // Deal initial hands
    dealer->hit();
    dealer->hit();
    dealer->hitPlayers();
    dealer->hitPlayers();

    // Add zero bets to the map for starting value lookup
    for (auto& player : *dealer->getPlayers()) {
        bets.insert_or_assign(player, 0);
    }

    // Get everyone's bets
    for (auto& player : *dealer->getPlayers()) {
        std::cout << "Player " << player->getName() << " - Balance " << player->getBlues() << std::endl;
        std::cout << "Please insert your bet > ";
        double playerBet;
        std::cin >> playerBet;
        bet(player, playerBet);
    }

    // Go until each player busts or stands
    for (auto& player : *dealer->getPlayers()) {
        bool quit = false;
        while (!quit) {
            switch (player->chooseAction()) {
                case Hit:
                    player->hit(dealer->getDeck()->getACard(), true);
                    if (player->sumOfHand(true) > 21) {
                        bust(player);
                        std::cout << "Player " << player->getName() << " has bust!" << std::endl;
                        quit = true;
                    }
                    break;
                case Stand:
                    quit = true;
                    break;
                case Split:
                    break;
            }
        }
    }

    // Go until the dealer busts or stands
    bool quit = false;
    while (!quit) {
        switch(dealer->chooseAction()) {
            case Hit:
                dealer->hit();
                break;
            case Stand:
                quit = true;
                break;
            case Split:
                break;
        }
    }

    // Show the game results and distribute winnings!
    for (auto& player : *dealer->getPlayers()) {
        auto playerHand = player->sumOfHand(true);
        auto dealerHand = dealer->sumOfHand();

        if (bets.at(player) == -1) continue;

        if (dealerHand > 21) {
            std::cout << "Dealer busted! Player " << player->getName() << " gets double dollars!" << std::endl;
            player->giveBlues(bets.at(player) * 2.0);
        } else if (playerHand == dealerHand) {
            std::cout << "Player " << player->getName() << " pushed!" << std::endl;
            player->giveBlues(bets.at(player));
        } else if (playerHand > dealerHand) {
            std::cout << "Player " << player->getName() << " won! Double dollars!" << std::endl;
            player->giveBlues(bets.at(player) * 2.0);
        } else {
            std::cout << "Player " << player->getName() << " lost! Nothing for you!" << std::endl;
        }
    }
}

Round::Round(Dealer* dealer) {
    this->dealer = dealer;
}

Round::~Round() = default;