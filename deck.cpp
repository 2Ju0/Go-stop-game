#include <iostream>

#include "hwatoo.cpp"
#include <queue>

// std::queue<Hwatoo> deck;

class Deck {
  // Constructor
 public:
  Hwatoo card_list_[51];

  Deck(Hwatoo* card) {
    for (int i = 0; i < number_of_card_; i++) {
      card_list_[i] = card[i];
    }
  }

  void reset(Hwatoo* card) {
    for (int i = 0; i < number_of_card_; i++) {
      card_list_[i] card[i];
    }
  }

  void devide() {
    // 2번 반복하여 바닥에는 6장(3장씩 두번), 플레이어는 7장씩(4장,3장) 돌아가도록 한다.
    bool flag = true;

    for (int i = 0; i < 2; i++) {

      for (int i = 0; i < 3; i++) { // 바닥
        Hwatoo elei

