#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

#include "cardListManager.h"

class Player {
 public:
  explicit Player(std::string name);
  CardListManager my_card_list_ = CardListManager();
  void setName(std::string name);
  std::string getName();
  void addCard(Hwatoo card);
  void removeCard(Hwatoo card);
  int sameCardCountInHandList(Hwatoo card);
  std::vector<Hwatoo> sameCardList(Hwatoo card);
  int getGoCount();
  void plusGoCount();
  int getTotalScore();
  void printHandList();
  std::vector<Hwatoo> getHandList();
  void setTempScore(int score);
  int getTempScore();
  void calTotalScore();
  int getBbukCount();
  void plusBbukCount();
  int getShakingCount();
  void plusShakingCount();
  bool winner_= false;

 private:
  std::vector<Hwatoo> hand_list_;
  std::vector<Hwatoo>::iterator itor;
  std::string player_name_;
  int go_count_ = 0;

  // score 관련
  int temp_score_ = 0;
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
  int shaking_count_ = 0;
  void calG();
  void calD();
  void calM();
  void calP();
};

#endif  // PLAYER_H
