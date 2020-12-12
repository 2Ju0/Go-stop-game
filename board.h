#ifndef GOSTOP_BOARD_H_
#define GOSTOP_BOARD_H_

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
#endif  // GOSTOP_BOARD_H_
