#include "rule.h"

void Rule::checkChongtong(Player* player) {
  int check_month_;
  int check_count_[13] = {
      0,
  };
  // 손 패에 있는 카드의 월... ex) 1월이면 index 1에 접근
  // check_count_의 index에 해당하는 원소에 +1
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
  // 바닥에 같은 월 카드 찾기 위한 리스트 생성
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    deck->floor.removeCard(*itor);
    break;
    // 같은 월 카드 먹은패로 이동, 바닥 패에서 지우기
  }
}

void Rule::getCardsFromFloor(Deck* deck, Player* now_p_, Hwatoo* card) {
  std::vector<Hwatoo> list = (deck->floor).sameCardList(*card);
  // 바닥에 같은 월 카드 찾기 위한 리스트 생성
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    deck->floor.removeCard(*itor);
    // 같은 월 카드 먹은패로 이동, 바닥 패에서 지우기
  }
}

void Rule::getCardsFromHand(Player* now_p_, Hwatoo* pick_card) {
  std::vector<Hwatoo> list = now_p_->sameCardList(*pick_card);
  // 손 패에서 같은 월 카드 찾기 위한 리스트 생성
  for (itor = list.begin(); itor != list.end(); ++itor) {
    now_p_->my_card_list_.eatCard(&(*itor));
    now_p_->removeCard(*itor);
    // 같은 월 카드 먹은패로 이동, 손 패에서 지우기
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
