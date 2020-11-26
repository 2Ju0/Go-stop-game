#include "player.h"

Player::Player(std::string name) : player_name_(name) {}  // Constructor

void Player::reset() {  // player 멤버 변수 초기화
  this->hand_list_.clear();
  this->go_count_ = 0;
  this->score_ = 0;
}

void Player::add_card(Hwatoo card) {  // plyaer의 손패 리스트에 카드 추가
  hand_list_.push_back(card);
}

void Player::throw_card(
    Hwatoo card) {  // player의 손패 리스트에서 특정 카드 삭제
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    if ((*itor).is_same(card)) {
      hand_list_.erase(itor++);
      return;
    } else {
      itor++;
    }
  }
}

int Player::get_go_count() { return this->go_count_; }  // 몇 go인지 확인

void Player::plus_go_count() { this->go_count_++; }  // go 값 증가

void Player::print_hand_list() {  // player의 카드 리스트 출력
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

int Player::get_total_score() { return this->score_; }  // player 점수 반환

void Player::cal_G() {
  std::list<Hwatoo> list = this->my_card_list_.get_g_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    char month = (*itor).getMonth();
    if (month == '1') {
      this->G_point_++;
    } else if (month == '3') {
      this->G_point_++;
    } else if (month == '8') {
      this->G_point_++;
    } else if (month == 'D') {
      this->G_point_++;
    } else {
      this->except_point_;
    }
  }

  if (this->G_point_ == 2 && this->except_point_ == 1) {
    this->score_ += 2;
    //비광 1개와 다른 종류의 광2개 먹은 경우
  } else if (this->G_point_ == 4 && this->except_point_ == 1) {
    this->score_ += 15;
  } else if (this->G_point_ >= 3) {
    this->score_ = G_point_ + except_point_;
  }
}

void Player::cal_D() {
  std::list<Hwatoo> list = this->my_card_list_.get_d_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    // 청단 확인
    char month = (*itor).getMonth();
    if (month == '6') {
      this->make_cheongdan_++;
      continue;
    } else if (month == '9') {
      this->make_cheongdan_++;
      continue;
    } else if (month == 'P') {
      this->make_cheongdan_++;
      continue;
    }
    // 홍단 확인
    if (month == '1') {
      this->make_hongdan_++;
      continue;
    } else if (month == '2') {
      this->make_hongdan_++;
      continue;
    } else if (month == '3') {
      this->make_hongdan_++;
      continue;
    }

    // 초단 확인
    if (month == '4') {
      this->make_chodan_++;
      continue;
    } else if (month == '5') {
      this->make_chodan_++;
      continue;
    } else if (month == '7') {
      this->make_chodan_++;
      continue;
    }
  }

  D_point_ = list.size();
  if (this->make_cheongdan_ == 3) {
    this->score_ += 3;
  }
  if (this->make_hongdan_ == 3) {
    this->score_ += 3;
  }
  if (this->make_chodan_ == 3) {
    this->score_ += 3;
  }
  if (this->D_point_ >= 5) {  // 띠가 5장 이상인 경우
    this->score_ += (this->D_point_ - 4);
  }
}

void Player::cal_M() {
  std::list<Hwatoo> list = this->my_card_list_.get_m_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    char month = (*itor).getMonth();
    if (month == '2') {
      this->make_godori_++;
    } else if (month == '4') {
      this->make_godori_++;
    } else if (month == '8') {
      this->make_godori_++;
    }
  }
  M_point_ = list.size();
  if (this->make_godori_ == 3) {  // 고도리 계산
    this->score_ += 5;
  }
  if (this->M_point_ >= 5) {  // 멍이 5개 이상인 경우
    this->score_ += (this->M_point_ - 4);
  }
}

void Player::cal_P() {
  std::list<Hwatoo> list = this->my_card_list_.get_p_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    std::string kind = (*itor).getKind();
    if (kind == "쌍") {
      this->P_point_ += 2;
    } else {
      this->P_point_ += 1;
    }
    if (this->P_point_ >= 10) {  // 피가 10개 이상인 경우
      this->score_ += (this->P_point_ - 9);
    }
  }
}

void Player::cal_total_score() {
  this->score_ = 0;
  this->cal_G();
  this->cal_M();
  this->cal_D();
  this->cal_P();
}

