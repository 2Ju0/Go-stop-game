#include "floor.h"

void Floor::addCard(Hwatoo card) {
  floor_list_.push_back(card);
}  // 바닥패 리스트에 카드 추가

Hwatoo* Floor::removeCard(Hwatoo card) { // 바닥 패에서 특정 카드 삭제
  for (itor = floor_list_.begin(); itor != floor_list_.end();) {
    if ((*itor).isSame(card)) {
      Hwatoo* card = &(*itor);
      floor_list_.erase(itor);
      return card;
    } else {
      ++itor;
    }
  }
  return nullptr;
}

bool Floor::isEmptyFloorList() {
  return this->floor_list_.empty();
}  // 바닥패가 리스트가 비어있는지 확인

void Floor::printCardList() {  // 바닥패 리스트 출력
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
      std::cout << (*itor).getMonth() << (*itor).getKind() << " ";
  }
}

// 매개변수로 받은 card와 floor_list에 같은 종류의 카드가 있다면 cnt를 증가하여
// 반환한다.
int Floor::sameCardCount(Hwatoo card) {
  int cnt = 0;
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).isSame(card)) cnt++;
  }
  return cnt;
}

// 매개변수로 받은 card와 floor_list에 같은 종류의 카드가 있다면 변수 list에
// 저장하여 반환한다.
std::vector<Hwatoo> Floor::sameCardList(Hwatoo card) {
  std::vector<Hwatoo> list;
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).isSame(card)) {
      list.push_back(*itor);
    }
  }
  return list;
}

