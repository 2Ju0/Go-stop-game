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

  std::list<Hwatoo> CardListManager::get_d_list() {  // 조커 리스트 반환
    return this->j_list_;
  }

  void CardListManager::reset() {  // 초기화
    this->g_list_.clear();
    this->m_list_.clear();
    this->d_list_.clear();
    this->p_list_.clear();
    // player의 경우 go_count, score_ 초기화 필요
  }

  void CardListManager::add_card(Hwatoo card) {  // 리스트에 카드 추가
    std::string temp = card.getKind();
    if (temp == "광") {
      this->g_list_.push_back(card);
    } else if (temp == "멍") {
      this->m_list_.push_back(card);
    } else if (temp == "띠") {
      this->d_list_.push_back(card);
    } else if (temp == "피") {
      this->p_list_.push_back(card);
    } else {
      this->j_list_.push_back(card);
    }
  }

  void CardListManager::remove_card(Hwatoo card) {  // 리스트에서 특정 카드 삭제
    std::string temp = card.getKind();
    std::list<Hwatoo> list;
    if (temp == "광") {
      list = this->g_list_;
    } else if (temp == "멍") {
      list = this->m_list_;
    } else if (temp == "띠") {
      list = this->d_list_;
    } else if (temp == "피") {
      list = this->d_list_;
    } else {
      list = this->j_list_;
    }

    for (itor = list.begin(); itor != list.end(); ++itor) {
      if ((*itor).is_same(card)) {
        list.erase(itor++);
        return;
      } else {
        itor++;
      }
    }
  }

  void CardListManager::print_card_list(
      std::string kind) {  // 특정 카드 리스트 출력
    std::list<Hwatoo> list;
    if (kind == "광") {
      list = this->g_list_;
    } else if (kind == "멍") {
      list = this->m_list_;
    } else if (kind == "띠") {
      list = this->d_list_;
    } else if (kind == "피") {
      list = this->d_list_;
    } else {
      list = this->j_list_;
    }
    for (itor = list.begin(); itor != list.end(); ++itor) {
      std::cout << (*itor).getName() << " ";
    }
    std::cout << std::endl;
  }
