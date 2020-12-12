#include "deck.h"

Deck::Deck(Hwatoo* card) {  // Constructor
  for (int i = 0; i < number_of_card_; i++) {
    card_list_.push_back(card[i]);
  }
}

void Deck::distributeCard() {
  // 2�� �ݺ��Ͽ� �ٴڿ��� 6��(3�徿 �ι�), �÷��̾�� 7�徿(4��,3��)
  // ���ư����� �Ѵ�.
  int count = 4;
  // std::cout << "distribute" << std::endl;
  for (int i = 0; i < 2; i++) {    // �ι��� ���� �����ش�.
    for (int i = 0; i < 3; i++) {  // �ٴڿ� 6�� : 3�徿 �ι�
      Hwatoo card = deck_list_.front();
      deck_list_.pop();
      floor.addCard(card);
    }

    for (int i = 0; i < count; i++) {
      Hwatoo card = deck_list_.front();  // player1 ���� 4��, 3��
      deck_list_.pop();
      player1.addCard(card);

      card = deck_list_.front();  // player2 ���� 4��, 3��
      deck_list_.pop();
      player2.addCard(card);

      card = deck_list_.front();  // player3 ���� 4��, 3��
      deck_list_.pop();
      player3.addCard(card);
    }
    count--;
  }
}

void Deck::gameStart() {  // ���� ���� �� ī�� ���� + deck(queue)�� �ֱ� +
                           // ī�� �й�( �ٴ�, �÷��̾�)
  cardShuffle();
  inputDeck();
  distributeCard();
}

void Deck::cardShuffle() {  // ī�� ����
  srand((unsigned)time(NULL));
  for (int i = 0; i < number_of_card_; i++) {
    int random = rand() % (number_of_card_);
    Hwatoo temp = card_list_.at(i);
    card_list_.at(i) = card_list_.at(random);
    card_list_.at(random) = temp;
  }
}

void Deck::inputDeck() {  // ī�� ����Ʈ�� ���� �ֱ�
  for (Hwatoo value : card_list_) {
    deck_list_.push(value);
  }
}