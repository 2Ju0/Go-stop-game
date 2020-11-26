#ifndef PLAYER_H
#define PLAYER_H

<<<<<<< HEAD
#include <string>
#include <list>
#include <iostream>
#include <queue>
=======
#include<string>
#include <list>
#include <iostream>
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985
#include "cardListManager.h"

class Player {
 public:
  explicit Player(std::string name);
  CardListManager my_card_list_ = CardListManager();
  void reset();
<<<<<<< HEAD
  std::string get_name();
=======
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985
  void add_card(Hwatoo card);
  void throw_card(Hwatoo card);
  int get_go_count();
  void plus_go_count();
  int get_total_score();
  void print_hand_list();
  void cal_total_score();
<<<<<<< HEAD
  int get_bbuk_count(); // Ãß°¡µÈ ºÎºÐ... »¶ Ä«¿îÆ®°¡ 3ÀÌ¸é °ÔÀÓ ³¡
  int get_bomb_count(); // Ãß°¡µÈ ºÎºÐ
=======
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985

 private:
  std::list<Hwatoo> hand_list_;
  std::list<Hwatoo>::iterator itor;
  std::string player_name_;
  int go_count_ = 0;
<<<<<<< HEAD
  bool winner = false; // winner°¡ trueÀÎ °æ¿ì °ÔÀÓ ³¡!

  // score °ü·Ã
=======
  // score ê´€ë ¨
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985
  int score_ = 0;
  int G_point_ = 0;
  int except_point_ = 0;
  int D_point_ = 0;
  int make_cheongdan_ = 0;
  int make_hongdan_ = 0;
  int make_chodan_ = 0;
  int M_point_ = 0;
  int make_godori_ = 0;
  int P_point_ = 0;
  int bbuk_count_ = 0;
<<<<<<< HEAD
  int bomb_count_ = 0; // Ãß°¡µÈ ºÎºÐ

  // Ãß°¡ µÈ ºÎºÐ
  // ÆøÅº ¹× ÃÑÅëÈ®ÀÎ
  int check_1 = 0;
  int check_2 = 0;
  int check_3 = 0;
  int check_4 = 0;
  int check_5 = 0;
  int check_6 = 0;
  int check_7 = 0;
  int check_8 = 0;
  int check_9 = 0;
  int check_10 = 0;
  int check_11 = 0;
  int check_12 = 0;

=======
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985
  void cal_G();
  void cal_D();
  void cal_M();
  void cal_P();
<<<<<<< HEAD
  void check_bomb(); // Ãß°¡µÈ ºÎºÐ
  void check_chongtong(); // Ãß°¡µÈ ºÎºÐ
};

#endif  // PLAYER_H
=======
};

#endif  // PLAYER_H
>>>>>>> bc4fd958c9c83ededc94c09ca90b7c70138c5985
