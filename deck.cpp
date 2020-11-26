#include "deck.h"

Deck::Deck(Hwatoo* card) {  // Constructor
  for (int i = 0; i < number_of_card_; i++) {
    card_list_.push_back(card[i]);
  }
}

void Deck::reset(Hwatoo* card) {  // Deck의 멤버 변수 초기화
  for (int i = 0; i < number_of_card_; i++) {
    card_list_[i] = card[i];
  }
  clear_deck();
  floor.reset();
  player1.reset();
  player2.reset();
  player3.reset();
}

Hwatoo Deck::pop_card() {  // 덱에서 한장 뒤집기
  Hwatoo card = this->deck_list_.front();
  this->deck_list_.pop();
  return card;
}

void Deck::divide_card() {
  // 2번 반복하여 바닥에는 6장(3장씩 두번), 플레이어는 7장씩(4장,3장)
  // 돌아가도록 한다.
  int count = 4;

  for (int i = 0; i < 2; i++) {    // 두번에 걸쳐 나눠준다.
    for (int i = 0; i < 3; i++) {  // 바닥에 6장 : 3장씩 두번
      Hwatoo card = deck_list_.front();
      deck_list_.pop();
      floor.add_card(card);
    }

    for (int i = 0; i < count; i++) {
      Hwatoo card = deck_list_.front();  // player1 에게 4장, 3장
      deck_list_.pop();
      player1.add_card(card);

      card = deck_list_.front();  // player2 에게 4장, 3장
      deck_list_.pop();
      player2.add_card(card);

      card = deck_list_.front();  // player3 에게 4장, 3장
      deck_list_.pop();
      player3.add_card(card);
    }
    count--;
  }
}

void Deck::game_start() {  // 게임 시작 전 카드 섞기 + deck(queue)에 넣기 +
                           // 카드 분배( 바닥, 플레이어)
  std::cout << "<고스톱 게임을 시작합니다>" << std::endl;
  std::cout << "=========================================================="
            << std::endl;
  std::cout << "player1의 이름을 설정하세요 : ";
  std::string name1, name2, name3;
  std::cin >> name1;
  player1.set_name(name1);
  std::cout << "player1의 이름: " << this->player1.get_name() << std::endl;

  std::cout << "player2의 이름을 설정하세요 : ";
  std::cin >> name2;
  player2.set_name(name2);
  std::cout << "player2의 이름: " << this->player2.get_name() << std::endl;

  std::cout << "player3의 이름을 설정하세요 : ";
  std::cin >> name3;
  player3.set_name(name3);
  std::cout << "player3의 이름: " << this->player3.get_name() << std::endl;
  card_shuffle();
  input_deck();
  divide_card();
}

void Deck::clear_deck() {  // deck 초기화
  std::queue<Hwatoo> empty;
  std::swap(this->deck_list_, empty);
}

void Deck::card_shuffle() {  // 카드 섞기
  srand((unsigned)time(NULL));
  for (int i = 0; i < number_of_card_; i++) {
    int random = rand() % (number_of_card_);
    Hwatoo temp = card_list_.at(i);
    card_list_.at(i) = card_list_.at(random);
    card_list_.at(random) = temp;
  }
}

void Deck::input_deck() {  // 카드 리스트를 덱에 넣기
  for (Hwatoo value : card_list_) {
    deck_list_.push(value);
  }
}

