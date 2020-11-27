#ifndef RULE_H
#define RULE_H

#include <iostream>
#include "floor.h"
#include "player.h"

class Rule {
 public:
  void bbuk(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
            Player curr_player, Player player2, Player player3);

  void ddadak(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
              Player curr_player, Player player2, Player player3);

  void jjok(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
            Player curr_player, Player player2, Player player3);

  void sseul(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
             Player curr_player, Player player2, Player player3);

  void check_chongtong(Player player);

 private:
  std::list<Hwatoo>::iterator itor;
  void get_cards_from_others(Player curr_player, Player player2,
                             Player player3);
};

#endif  // RULE_H
