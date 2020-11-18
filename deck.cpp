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
      card_list_[i] = card[i];
    }
  }

  void devide() {
    // 2번 반복하여 바닥에는 6장(3장씩 두번), 플레이어는 7장씩(4장,3장) 돌아가도록 한다.
    bool flag = true;

    for (int i = 0; i < 2; i++) {

      for (int i = 0; i < 3; i++) { // 바닥
        Hwatoo element = deck.front();
        deck.pop();
        
      }

    }
  }

  void game_start() { 
    card_shuffle();
    input_deck();
    devide();
  }

 private:
  const int number_of_card_ = 51;
  std::queue<Hwatoo> deck;

  void card_shuffle() {
    for (int i = 0; i < number_of_card_; i++) {
      Hwatoo temp;
      temp = card_list_[i];
      card_list_[i] = card_list_[(rand() % (number_of_card_ - i)) + i];
      card_list_[(rand() % (number_of_card_ - i)) + i] = temp;
    }
  }

  void input_deck() {
    for (Hwatoo value : card_list_) {
      deck.push(value);
    }
  }
};

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
      Hwatoo("Jocker"), Hwatoo("Jocker"), Hwatoo("Jocker")};

  Deck deck = Deck(card);
  for (int i = 0; i < 51; i++) {
    std::cout << deck.card_list_[i].getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  deck.game_start();
  for (int i = 0; i < 51; i++) {
    std::cout << deck.card_list_[i].getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;

  deck.reset(card);
  for (int i = 0; i < 51; i++) {
    std::cout << deck.card_list_[i].getName() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  
  std::cout << deck.card_list_[0].is_same(Hwatoo("1광"));
}

