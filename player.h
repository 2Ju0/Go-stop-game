#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>
#include <iostream>
#include <queue>
#include "cardListManager.h"

class Player {
 public:
  explicit Player(std::string name);
  CardListManager my_card_list_ = CardListManager();
  void reset();
  std::string get_name();
  void add_card(Hwatoo card);
  void throw_card(Hwatoo card);
  int get_go_count();
  void plus_go_count();
  int get_total_score();
  void print_hand_list();
  void cal_total_score();
  int get_bbuk_count(); // 추가된 부분... 뻑 카운트가 3이면 게임 끝
  int get_bomb_count(); // 추가된 부분

 private:
  std::list<Hwatoo> hand_list_;
  std::list<Hwatoo>::iterator itor;
  std::string player_name_;
  int go_count_ = 0;
  bool winner = false; // winner가 true인 경우 게임 끝!

  // score 관련
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
  int bomb_count_ = 0; // 추가된 부분

  // 추가 된 부분
  // 폭탄 및 총통확인
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

  void cal_G();
  void cal_D();
  void cal_M();
  void cal_P();
  void check_bomb(); // 추가된 부분
  void check_chongtong(); // 추가된 부분
};

#endif  // PLAYER_H