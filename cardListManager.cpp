#include "cardListManager.h"

std::list<Hwatoo> CardListManager::get_g_list() {  // 광 리스트 반환
  return this->g_list_;
}

std::list<Hwatoo> CardListManager::get_m_list() {  // 멍 리스트 반환
  return this->m_list_;
}

std::list<Hwatoo> CardListManager::get_d_list() {  // 띠 리스트 반환
  return this->d_list_;
}

std::list<Hwatoo> CardListManager::get_p_list() {  // 피 리스트 반환 (피, 쌍피, 조커)
  return this->p_list_;
}
std::list<Hwatoo> CardListManager::get_list_type(Hwatoo card) {
  std::list<Hwatoo> list;
  std::string temp = card.getKind();
  if (temp == "광") {
    list = this->g_list_;
  } else if (temp == "멍") {
    list = this->m_list_;
  } else if (temp == "띠") {
    list = this->d_list_;
  } else {
    list = this->p_list_;
  }
  return list;
}

void CardListManager::add_card(Hwatoo* card) {  // 리스트에 카드 추가
  if (card != nullptr) {  // nullptr인 경우(상대가 피가 없는 경우) 있으므로
                          // 매개변수 포인터 변수로 바꿈
    std::list<Hwatoo> list = this->get_list_type(*card);
    list.push_back(*card);
  }
}

Hwatoo* CardListManager::steal_card() {  // 다른 player에게 카드 뺏기는 경우
                                         // 피 리스트에서 카드 하나 삭제하고 삭제한 카드 주소 반환
  if (!this->p_list_.empty()) {
    Hwatoo card = this->p_list_.back();
    p_list_.pop_back();
    return &card;
  }
  return nullptr;  // 패가 없는 경우 (리스트가 비어있는 경우) null반환
}

void CardListManager::remove_card(Hwatoo* card) {
  if (card != nullptr) {  // card가 null이 아니라면
    std::list<Hwatoo> list = this->get_list_type(*card);
    // 해당 리스트에서 카드 삭제
    for (itor = list.begin(); itor != list.end(); ++itor) {
      if ((*itor).is_same(*card)) {
        list.erase(itor++);
      } else {
        itor++;
      }
    }
  }
}

void CardListManager::print_g_list() {  // 광 카드 리스트 출력
  for (itor = this->g_list_.begin(); itor != g_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::print_m_list() {  // 멍 카드 리스트 출력
  for (itor = this->m_list_.begin(); itor != m_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::print_d_list() {  // 띠 카드 리스트 출력
  for (itor = this->d_list_.begin(); itor != d_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::print_p_list() {  // 피 및 조커 카드 리스트 출력
  for (itor = this->p_list_.begin(); itor != p_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}
