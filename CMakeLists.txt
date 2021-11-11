cmake_minimum_required(VERSION 3.18)
project(BlueJack)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlueJack main.cpp cards.h hand.cpp hand.h player.cpp player.h cards.cpp dealer.cpp dealer.h)
