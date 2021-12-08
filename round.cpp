#include <iostream>
#include "round.h"
#include <cstdarg>

Round::Round() = default;

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

void Round::hitPlayers() {
    auto deck = dealer->getDeck();
    for (auto& [player, _] : bets) {
        player->hit(deck->getACard(), true);
    }
}

void Round::joinPlayers(int num, ...) {
    va_list valist;
    va_start(valist, num);
    for (int i = 0; i < num; i++) {
        bets.insert_or_assign(va_arg(valist, Player*), 0);
    }
    va_end(valist);
}

void Round::joinDealer(Dealer* givenDealer) {
    dealer = givenDealer;
}

void Round::go() {
    // Deal initial hands
    dealer->hit();
    dealer->hit();
    hitPlayers();
    hitPlayers();

    // Get everyone's bets
    for (auto& [player, _] : bets) {
        std::cout << "Player " << player->getName() << " - Balance " << player->getBlues() << std::endl;
        std::cout << "Please insert your bet > ";
        double playerBet;
        std::cin >> playerBet;
        bet(player, playerBet);
    }

    // Go until each player busts or stands
    for (auto& [player, _] : bets) {
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
    for (auto& [player, bet] : bets) {
        if (bet == -1) continue;

        auto playerHand = player->sumOfHand(true);
        auto dealerHand = dealer->sumOfHand();

        if (dealerHand > 21) {
            std::cout << "Dealer busted! Player " << player->getName() << " gets double dollars!" << std::endl;
            player->giveBlues(bet * 2.0);
        } else if (playerHand == dealerHand) {
            std::cout << "Player " << player->getName() << " pushed!" << std::endl;
            player->giveBlues(bet);
        } else if (playerHand > dealerHand) {
            std::cout << "Player " << player->getName() << " won! Double dollars!" << std::endl;
            player->giveBlues(bet * 2.0);
        } else {
            std::cout << "Player " << player->getName() << " lost! Nothing for you!" << std::endl;
        }
    }
}

Round::~Round() = default;