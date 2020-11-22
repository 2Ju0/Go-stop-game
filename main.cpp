#include <iostream>

#include "deck.h"
#include "hwatoo.h"

int main() {
  Hwatoo card[51] = {
      Hwatoo("1광"),    Hwatoo("1띠"),    Hwatoo("1피"),   Hwatoo("1피"),
      Hwatoo("2멍"),    Hwatoo("2띠"),    Hwatoo("2피"),   Hwatoo("2피"),
      Hwatoo("3광"),    Hwatoo("3띠"),    Hwatoo("3피"),   Hwatoo("3피"),
      Hwatoo("4멍"),    Hwatoo("4띠"),    Hwatoo("4피"),   Hwatoo("4피"),
      Hwatoo("5멍"),    Hwatoo("5띠"),    Hwatoo("5피"),   Hwatoo("5피"),
      Hwatoo("6멍"),    Hwatoo("6띠"),    Hwatoo("6피"),   Hwatoo("6피"),
      Hwatoo("7멍"),    Hwatoo("7띠"),    Hwatoo("7피"),   Hwatoo("7피"),
      Hwatoo("8광"),    Hwatoo("8멍"),    Hwatoo("8피"),   Hwatoo("8피"),
      Hwatoo("9쌍"),    Hwatoo("9띠"),    Hwatoo("9피"),   Hwatoo("9피"),
      Hwatoo("P멍"),    Hwatoo("P띠"),    Hwatoo("P피"),   Hwatoo("P피"),
      Hwatoo("D광"),    Hwatoo("D피"),    Hwatoo("D피"),   Hwatoo("D쌍"),
      Hwatoo("B광"),    Hwatoo("B멍"),    Hwatoo("B띠"),   Hwatoo("B쌍"),
      Hwatoo("J쌍"), Hwatoo("J쌍"), Hwatoo("J쌍")};

  Deck deck = Deck(card);  // deck 객체 생성
  // 초기 card list
  std::cout << "초기 card list 출력" << std::endl;
  for (int i = 0; i < 51; i++) {
    std::cout << deck.card_list_.at(i).getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  // 게임 시작 (카드 섞기 + 카드 분배)
  deck.game_start();
  std::cout << "섞인 카드 출력" << std::endl;
  for (int i = 0; i < 51; i++) {  // 카드가 잘 섞였는지 확인
    std::cout << deck.card_list_.at(i).getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "deck_list 출력" << std::endl;
  while (!deck.deck_list_.empty()) {
    std::cout << deck.deck_list_.front().getName() << " ";
    deck.deck_list_.pop();
  }
  std::cout << std::endl;
  std::cout << std::endl;

  // 카드를 player, floor 에게 잘 나눠줬는지 확인
  std::cout << "player1 패 리스트 출력" << std::endl;
  deck.player1.print_card_list();
  std::cout << std::endl;

  std::cout << "player2 패 리스트 출력" << std::endl;
  deck.player2.print_card_list();
  std::cout << std::endl;

  std::cout << "player3 패 리스트 출력" << std::endl;
  deck.player3.print_card_list();
  std::cout << std::endl;

  std::cout << "floor 패 리스트 출력" << std::endl;
  deck.floor.print_card_list();
  std::cout << std::endl;

  std::cout << "reset 후 card list 출력" << std::endl;
  deck.reset(card);  // deck, player, floor 초기화
  for (int i = 0; i < 51; i++) {
    std::cout << deck.card_list_.at(i).getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "reset 후 deck_list 출력" << std::endl;
  while (!deck.deck_list_.empty()) {
    std::cout << deck.deck_list_.front().getName() << " ";
    deck.deck_list_.pop();
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "reset 후 player1 패 리스트 출력" << std::endl;
  deck.player1.print_card_list();
  std::cout << std::endl;

  std::cout << "reset 후 player2 패 리스트 출력" << std::endl;
  deck.player2.print_card_list();
  std::cout << std::endl;

  std::cout << "reset 후 player3 패 리스트 출력" << std::endl;
  deck.player3.print_card_list();
  std::cout << std::endl;

  std::cout << "reset 후 floor 패 리스트 출력" << std::endl;
  deck.floor.print_card_list();
  std::cout << std::endl;
}
