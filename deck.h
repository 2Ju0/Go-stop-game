#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>

#include "floor.h"
#include "player.h"

class Deck {
 public:
  std::vector<Hwatoo>
      card_list_;  // main문 출력 위해 잠시 public으로 (원래는 private)
  std::queue<Hwatoo> deck_list_;       // deck이 가지는 패 리스트(마찬가지로 원래 private)
  Floor floor = Floor();     // floor 객체
  Player player1 = Player("player1");  // player1 객체
  Player player2 = Player("player2");  // player2 객체
  Player player3 = Player("player3");  // player3 객체

  Deck(Hwatoo* card); // constructor
  void reset(Hwatoo* card);
  Hwatoo pop_card();
  void game_start();

 private:
  const int number_of_card_ = 51;  // 카드 개수 51개로 고정
  void clear_deck();
  void card_shuffle();
  void input_deck();
  void divide_card();
};


