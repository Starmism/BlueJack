cmake_minimum_required(VERSION 3.18)
project(BlueJack)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlueJack main.cpp hand.cpp player.cpp cards.cpp dealer.cpp round.cpp round.h)
