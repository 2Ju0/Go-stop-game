#include "cardListManager.h"

std::vector<Hwatoo> CardListManager::getGList() {  // 광 리스트 반환
  return this->g_list_;
}

std::vector<Hwatoo> CardListManager::getMList() {  // 멍 리스트 반환
  return this->m_list_;
}

std::vector<Hwatoo> CardListManager::getDList() {  // 띠 리스트 반환
  return this->d_list_;
}

std::vector<Hwatoo>
CardListManager::getPList() {  // 피 리스트 반환 (피, 쌍피, 조커)
  return this->p_list_;
}

void CardListManager::eatCard(Hwatoo* card) {  // 리스트에 카드 추가
  if (card != nullptr) {
    std::string temp = (*card).getKind();
    if (temp == "광") {
      this->g_list_.push_back(*card);
    } else if (temp == "멍") {
      this->m_list_.push_back(*card);
    } else if (temp == "띠") {
      this->d_list_.push_back(*card);
    } else {
      this->p_list_.push_back(*card);
    }
  }
}

// 다른 player에게 카드 뺏기는 경우  피 리스트에서 카드 하나 삭제하고 삭제한
// 카드 주소 반환
Hwatoo* CardListManager::stealCard() {
  if (!p_list_.empty()) {
    return &this->p_list_.back();
  }
  return nullptr;  // 패가 없는 경우 (리스트가 비어있는 경우) null반환
}

void CardListManager::removePCard() {
  if (!p_list_.empty()) {
    p_list_.pop_back();
  }
}

void CardListManager::printGList() {  // 광 카드 리스트 출력
  for (itor = this->g_list_.begin(); itor != g_list_.end(); ++itor) {
    std::cout << (*itor).getMonth() << (*itor).getKind() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::printMList() {  // 멍 카드 리스트 출력
  for (itor = this->m_list_.begin(); itor != m_list_.end(); ++itor) {
    std::cout << (*itor).getMonth() << (*itor).getKind() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::printDList() {  // 띠 카드 리스트 출력
  for (itor = this->d_list_.begin(); itor != d_list_.end(); ++itor) {
    std::cout << (*itor).getMonth() << (*itor).getKind() << " ";
  }
  std::cout << std::endl;
}

void CardListManager::printPList() {  // 피 카드 리스트 출력
  int jump = 6;
  int count = 0;
  for (itor = this->p_list_.begin(); itor != p_list_.end(); ++itor) {
    std::cout << (*itor).getMonth() << (*itor).getKind() << " ";
    count++;
    if (count == jump) {
      std::cout << std::endl;
      std::cout << "     ";
      count = 0;
    }
  }
  std::cout << std::endl;
}

