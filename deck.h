#ifndef GOSTOP_DECK_H_
#define GOSTOP_DECK_H_

#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#include "floor.h"
#include "player.h"

class Deck {
 public:
  std::vector<Hwatoo>
      card_list_;
  std::queue<Hwatoo>
      deck_list_;  // deck이 가지는 패 리스트
  Floor floor = Floor();               // floor 객체
  Player player1 = Player("player1");  // player1 객체
  Player player2 = Player("player2");  // player2 객체
  Player player3 = Player("player3");  // player3 객체

  Deck(Hwatoo* card);  // constructor
  void gameStart();

 private:
  const int number_of_card_ = 48;  // 카드 개수 48개로 고정
  void clearDeck();
  void cardShuffle();
  void inputDeck();
  void distributeCard();
};

#endif  // GOSTOP_DECK_H_
