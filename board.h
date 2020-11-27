#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "floor.h"
#include "player.h"

class Board {
  public:
  void printBoard(Floor floor, Player player1, Player player2, Player player3);
};
#endif // BOARD_H
