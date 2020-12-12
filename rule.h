#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <vector>

#include "deck.h"

class Rule {
 public:
  void checkChongtong(Player* player);
  void getCardsFromFloorWithBreak(Deck* deck, Player* now_p_, Hwatoo* card);
  void getCardsFromFloor(Deck* deck, Player* now_p_, Hwatoo* card);
  void getCardsFromOthers(Player* now_p_, Player* other1_p_, Player* other2_p_);

 private:
  std::vector<Hwatoo>::iterator itor;
};

#endif  // RULE_H
