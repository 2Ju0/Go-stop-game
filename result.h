#ifndef RESULT_H
#define RESULT_H

#include <iostream>

#include "player.h"
#include "deck.h"

// pay_point 는 실제 게임에서는 돈을 얼마 내야하는지인데
// 프로그램에서는 포인트로 돈을 대체

class Result {
public:
  int number_of_game_ = 0;
  void result(Player* Winner, Player* loser1, Player* loser2);
};

#endif  // RESULT_H