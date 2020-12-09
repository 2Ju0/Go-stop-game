#ifndef DECK_H
#define DECK_H

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
    card_list_;  // main�� ��� ���� ��� public���� (������ private)
  std::queue<Hwatoo>
    deck_list_;  // deck�� ������ �� ����Ʈ(���������� ���� private)
  Floor floor = Floor();               // floor ��ü
  Player player1 = Player("player1");  // player1 ��ü
  Player player2 = Player("player2");  // player2 ��ü
  Player player3 = Player("player3");  // player3 ��ü

  Deck(Hwatoo* card);  // constructor
  void gameStart();

private:
  const int number_of_card_ = 48;  // ī�� ���� 48���� ����
  void cardShuffle();
  void inputDeck();
  void distributeCard();
};

#endif  // DECK_H