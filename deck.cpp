#include "deck.h"

Deck::Deck(Hwatoo* card) {  // Constructor
  for (int i = 0; i < number_of_card_; i++) {
    card_list_.push_back(card[i]);
  }
}

void Deck::distributeCard() {
  // 2번 반복하여 바닥에는 6장(3장씩 두번), 플레이어는 7장씩(4장,3장)
  // 돌아가도록 한다.
  int count = 4;
  // std::cout << "distribute" << std::endl;
  for (int i = 0; i < 2; i++) {    // 두번에 걸쳐 나눠준다.
    for (int i = 0; i < 3; i++) {  // 바닥에 6장 : 3장씩 두번
      Hwatoo card = deck_list_.front();
      deck_list_.pop();
      floor.addCard(card);
    }

    for (int i = 0; i < count; i++) {
      Hwatoo card = deck_list_.front();  // player1 에게 4장, 3장
      deck_list_.pop();
      player1.addCard(card);

      card = deck_list_.front();  // player2 에게 4장, 3장
      deck_list_.pop();
      player2.addCard(card);

      card = deck_list_.front();  // player3 에게 4장, 3장
      deck_list_.pop();
      player3.addCard(card);
    }
    count--;
  }
}

void Deck::gameStart() {  // 게임 시작 전 카드 섞기 + deck(queue)에 넣기 +
                           // 카드 분배( 바닥, 플레이어)
  cardShuffle();
  inputDeck();
  distributeCard();
}

void Deck::cardShuffle() {  // 카드 섞기
  srand((unsigned)time(NULL));
  for (int i = 0; i < number_of_card_; i++) {
    int random = rand() % (number_of_card_);
    Hwatoo temp = card_list_.at(i);
    card_list_.at(i) = card_list_.at(random);
    card_list_.at(random) = temp;
  }
}

void Deck::inputDeck() {  // 카드 리스트를 덱에 넣기
  for (Hwatoo value : card_list_) {
    deck_list_.push(value);
  }
}