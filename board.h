#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

#include "deck.h"

class Board {
public:
  void gameStart(Deck* deck);
  void gameOver();
  void printPlayer(Player player);
  void printFloor(Floor floor);
  void line();
};
#endif  // BOARD_H