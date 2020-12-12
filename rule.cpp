#include "rule.h"

void Rule::checkChongtong(Player* player) {
  int check_month_;
  int check_count_[13] = {
      0,
  };
  // �� �п� �ִ� ī���� ��... ex) 1���̸� index 1�� ����
  // check_count_�� index�� �ش��ϴ� ���ҿ� +1
  if (!(*player).getHandList().empty()) {
    for (int i = 0; i < (*player).getHandList().size(); i++) {
      check_month_ = (*player).getHandList()[i].getMonth();
      check_count_[check_month_]++;
    }
    for (int i = 1; i < 13; i++) {
      if (check_count_[i] == 4) {
        (*player).winner_ = true;
        break;
      }
    }
  }
}

void Rule::getCardsFromFloorWithBreak(Deck* deck, Player* now_p_,
  Hwatoo* card) {
  std::vector<Hwatoo> list = (deck->floor).sameCardList(*card);
  // �ٴڿ� ���� �� ī�� ã�� ���� ����Ʈ ����
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    deck->floor.removeCard(*itor);
    break;
    // ���� �� ī�� �����з� �̵�, �ٴ� �п��� �����
  }
}

void Rule::getCardsFromFloor(Deck* deck, Player* now_p_, Hwatoo* card) {
  std::vector<Hwatoo> list = (deck->floor).sameCardList(*card);
  // �ٴڿ� ���� �� ī�� ã�� ���� ����Ʈ ����
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    deck->floor.removeCard(*itor);
    // ���� �� ī�� �����з� �̵�, �ٴ� �п��� �����
  }
}

void Rule::getCardsFromHand(Player* now_p_, Hwatoo* pick_card) {
  std::vector<Hwatoo> list = now_p_->sameCardList(*pick_card);
  // �� �п��� ���� �� ī�� ã�� ���� ����Ʈ ����
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    now_p_->removeCard(*itor);
    // ���� �� ī�� �����з� �̵�, �� �п��� �����
  }
}

void Rule::getCardsFromOthers(Player* now_p_, Player* other1_p_,
  Player* other2_p_) {
  Hwatoo* card = other1_p_->my_card_list_.stealCard();
  now_p_->my_card_list_.eatCard(card);
  other1_p_->my_card_list_.removePCard();
  card = other2_p_->my_card_list_.stealCard();
  now_p_->my_card_list_.eatCard(card);
  other2_p_->my_card_list_.removePCard();
}
