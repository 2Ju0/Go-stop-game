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

std::list<Hwatoo> CardListManager::get_p_list() {  // 피 리스트 반환
  return this->p_list_;
}

void CardListManager::add_card(Hwatoo card) {  // 리스트에 카드 추가
  std::string temp = card.getKind();
  if (temp == "광") {
    this->g_list_.push_back(card);
  } else if (temp == "멍") {
    this->m_list_.push_back(card);
  } else if (temp == "띠") {
    this->d_list_.push_back(card);
  } else {
    this->p_list_.push_back(card);
  }
}

Hwatoo CardListManager::steal_card() {  // 리스트에서 특정 카드 삭제
  if (!this->g_list_.empty()) {
    Hwatoo card = this->p_list_.back();
    p_list_.pop_back();
    return card;
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

