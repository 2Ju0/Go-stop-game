#include "player.h"

Player::Player(std::string name) : player_name_(name) {}  // Constructor

// 매개변수로 받은 card와 floor_list에 같은 종류의 카드가 있다면 변수 list에
// 저장하여 반환한다.
std::vector<Hwatoo> Player::sameCardList(Hwatoo card) {
  std::vector<Hwatoo> list;
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    if ((*itor).isSame(card)) {
      list.push_back(*itor);
    }
  }
  return list;
}

void Player::setName(std::string name) {
  this->player_name_ = name;
}  // player 이름 설정

std::string Player::getName() {
  return this->player_name_;
}  // player 이름 반환

void Player::addCard(Hwatoo card) {  // player의 손패 리스트에 카드 추가
  hand_list_.push_back(card);
}

void Player::removeCard(
  Hwatoo card) {  // player의 손패 리스트에서 특정 카드 삭제
  for (itor = hand_list_.begin(); itor != hand_list_.end();) {
    if ((*itor).getName() == card.getName()) {
      hand_list_.erase(itor);
      return;
    }
    else {
      ++itor;
    }
  }
}

int Player::sameCardCountInHandList(Hwatoo card) {
  int cnt = 0;
  for (itor = this->hand_list_.begin(); itor != this->hand_list_.end();
    ++itor) {
    if ((*itor).isSame(card)) {
      cnt++;
    }
  }
  return cnt;
}

int Player::getGoCount() { return this->go_count_; }  // 몇 go인지 확인

void Player::plusGoCount() { this->go_count_++; }  // go 값 증가

void Player::printHandList() {  // player의 카드 리스트 출력
  int number = 0;
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    std::cout << "[" << number++ << "]" << (*itor).getMonth() << (*itor).getKind() << " ";
  }
  std::cout << std::endl;
}

std::vector<Hwatoo> Player::getHandList() {
  return this->hand_list_;
}  // player의 손패 리스트 반환

void Player::setTempScore(int score) { this->temp_score_ = score; }

int Player::getTempScore() { return this->temp_score_; }

int Player::getTotalScore() { return this->score_; }  // player 점수 반환

int Player::getBbukCount() { return this->bbuk_count_; }  // 뻑 횟수 반환

void Player::plusBbukCount() { this->bbuk_count_++; }  // 뻑 횟수 증가

int Player::getShakingCount() {
  return this->shaking_count_;
}  // 흔들기 횟수 반환

void Player::plusShakingCount() {
  this->shaking_count_++;
}  // 흔들기 횟수 증가

void Player::calG() {  // 광 계산
  this->G_point_ = 0;
  this->except_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getGList();

  // 광 개수 증가시키는 부분
  for (itor = list.begin(); itor != list.end(); ++itor) {
    int month = (*itor).getMonth();
    if (month == 12) {  // 비광 개수 증가
      this->except_point_++;
    }
  }
  this->G_point_ = list.size();
  if (this->G_point_ == 5) {  // 5광
    this->score_ += 15;
  }
  else if (this->G_point_ == 4) {  // 4광
    this->score_ += 4;
  }
  else if (this->G_point_ == 3) {  // 3광
    if (this->except_point_ == 1) {  // 비광포함
      this->score_ += 2;
    }
    else {
      this->score_ += 3;
    }
  }
}

void Player::calD() {  // 띠 계산
  this->make_cheongdan_ = 0;
  this->make_chodan_ = 0;
  this->make_hongdan_ = 0;
  this->D_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getDList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    // 청단 확인
    int month = (*itor).getMonth();
    if (month == 6 || month == 9 || month == 10) {
      this->make_cheongdan_++;
    }
    // 홍단 확인
    if (month == 1 || month == 2 || month == 3) {
      this->make_hongdan_++;
    }
    // 초단 확인
    if (month == 4 || month == 5 || month == 7) {
      this->make_chodan_++;
    }
  }

  D_point_ = list.size();
  if (this->D_point_ >= 5) {  // 띠가 5장 이상인 경우
    this->score_ += (this->D_point_ - 4);
  }
  if (this->make_cheongdan_ == 3) {
    this->score_ += 3;
  }
  if (this->make_hongdan_ == 3) {
    this->score_ += 3;
  }
  if (this->make_chodan_ == 3) {
    this->score_ += 3;
  }
}

void Player::calM() {  // 멍 계산
  this->M_point_ = 0;
  this->make_godori_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getMList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    int month = (*itor).getMonth();
    if (month == 2 || month == 4 || month == 8) {
      this->make_godori_++;
    }
  }
  if (this->make_godori_ == 3) {  // 고도리 계산
    this->score_ += 5;
  }
  M_point_ = list.size();
  if (this->M_point_ >= 5) {  // 멍이 5개 이상인 경우
    this->score_ += (this->M_point_ - 4);
  }
}

void Player::calP() {  // 피 계산
  this->P_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getPList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    std::string kind = (*itor).getKind();
    if (kind == "쌍") {
      this->P_point_ += 2;
    }
    else {
      this->P_point_ += 1;
    }
  }

  if (this->P_point_ >= 10) {  // 피가 10개 이상인 경우
    this->score_ += (this->P_point_ - 9);
  }
}

void Player::calTotalScore() {  // 최종 점수 계산
  this->score_ = 0;
  this->calG();
  this->calM();
  this->calD();
  this->calP();
}