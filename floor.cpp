#include "floor.h"

void Floor::reset() { floor_list_.clear(); }

void Floor::add_card(Hwatoo card) { floor_list_.push_back(card); }

void Floor::remove_card(Hwatoo card) {
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).is_same(card)) {
      floor_list_.erase(itor++);
      return;
    } else {
      itor++;
    }
  }
}

bool Floor::is_empty_floor_list() { return this->floor_list_.empty(); }

void Floor::print_card_list() {
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

// 매개변수로 받은 card와 floor_list에 같은 종류의 카드가 있다면 cnt를 증가하여 반환한다.
int Floor::same_card_count(Hwatoo card) { 
  int cnt = 0;
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).is_same(card)) cnt++;
  }
  return cnt;
}

// 매개변수로 받은 card와 floor_list에 같은 종류의 카드가 있다면 변수 list에 저장하여 반환한다.
std::list<Hwatoo> Floor::same_card_list(Hwatoo card) {
  std::list<Hwatoo> list;
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).is_same(card)) list.push_back(*itor);
  }
  return list;
}
