#ifndef RESULT_H
#define RESULT_H

#include <iostream>

#include "player.h"
#include "deck.h"

// pay_point �� ���� ���ӿ����� ���� �� �����ϴ����ε�
// ���α׷������� ����Ʈ�� ���� ��ü

class Result {
public:
  int number_of_game_ = 0;
  void result(Player* Winner, Player* loser1, Player* loser2);
};

#endif  // RESULT_H