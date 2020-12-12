#include "player.h"

Player::Player(std::string name) : player_name_(name) {}  // Constructor

// �Ű������� ���� card�� floor_list�� ���� ������ ī�尡 �ִٸ� ���� list��
// �����Ͽ� ��ȯ�Ѵ�.
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
}  // player �̸� ����

std::string Player::getName() {
  return this->player_name_;
}  // player �̸� ��ȯ

void Player::addCard(Hwatoo card) {  // player�� ���� ����Ʈ�� ī�� �߰�
  hand_list_.push_back(card);
}

void Player::removeCard(
  Hwatoo card) {  // player�� ���� ����Ʈ���� Ư�� ī�� ����
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

int Player::getGoCount() { return this->go_count_; }  // �� go���� Ȯ��

void Player::plusGoCount() { this->go_count_++; }  // go �� ����

void Player::printHandList() {  // player�� ī�� ����Ʈ ���
  int number = 0;
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    std::cout << "[" << number++ << "]" << (*itor).getMonth() << (*itor).getKind() << " ";
  }
  std::cout << std::endl;
}

std::vector<Hwatoo> Player::getHandList() {
  return this->hand_list_;
}  // player�� ���� ����Ʈ ��ȯ

void Player::setTempScore(int score) { this->temp_score_ = score; }

int Player::getTempScore() { return this->temp_score_; }

int Player::getTotalScore() { return this->score_; }  // player ���� ��ȯ

int Player::getBbukCount() { return this->bbuk_count_; }  // �� Ƚ�� ��ȯ

void Player::plusBbukCount() { this->bbuk_count_++; }  // �� Ƚ�� ����

int Player::getShakingCount() {
  return this->shaking_count_;
}  // ���� Ƚ�� ��ȯ

void Player::plusShakingCount() {
  this->shaking_count_++;
}  // ���� Ƚ�� ����

void Player::calG() {  // �� ���
  this->G_point_ = 0;
  this->except_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getGList();

  // �� ���� ������Ű�� �κ�
  for (itor = list.begin(); itor != list.end(); ++itor) {
    int month = (*itor).getMonth();
    if (month == 12) {  // �� ���� ����
      this->except_point_++;
    }
  }
  this->G_point_ = list.size();
  if (this->G_point_ == 5) {  // 5��
    this->score_ += 15;
  }
  else if (this->G_point_ == 4) {  // 4��
    this->score_ += 4;
  }
  else if (this->G_point_ == 3) {  // 3��
    if (this->except_point_ == 1) {  // ������
      this->score_ += 2;
    }
    else {
      this->score_ += 3;
    }
  }
}

void Player::calD() {  // �� ���
  this->make_cheongdan_ = 0;
  this->make_chodan_ = 0;
  this->make_hongdan_ = 0;
  this->D_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getDList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    // û�� Ȯ��
    int month = (*itor).getMonth();
    if (month == 6 || month == 9 || month == 10) {
      this->make_cheongdan_++;
    }
    // ȫ�� Ȯ��
    if (month == 1 || month == 2 || month == 3) {
      this->make_hongdan_++;
    }
    // �ʴ� Ȯ��
    if (month == 4 || month == 5 || month == 7) {
      this->make_chodan_++;
    }
  }

  D_point_ = list.size();
  if (this->D_point_ >= 5) {  // �찡 5�� �̻��� ���
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

void Player::calM() {  // �� ���
  this->M_point_ = 0;
  this->make_godori_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getMList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    int month = (*itor).getMonth();
    if (month == 2 || month == 4 || month == 8) {
      this->make_godori_++;
    }
  }
  if (this->make_godori_ == 3) {  // ���� ���
    this->score_ += 5;
  }
  M_point_ = list.size();
  if (this->M_point_ >= 5) {  // ���� 5�� �̻��� ���
    this->score_ += (this->M_point_ - 4);
  }
}

void Player::calP() {  // �� ���
  this->P_point_ = 0;
  std::vector<Hwatoo> list = this->my_card_list_.getPList();

  for (itor = list.begin(); itor != list.end(); ++itor) {
    std::string kind = (*itor).getKind();
    if (kind == "��") {
      this->P_point_ += 2;
    }
    else {
      this->P_point_ += 1;
    }
  }

  if (this->P_point_ >= 10) {  // �ǰ� 10�� �̻��� ���
    this->score_ += (this->P_point_ - 9);
  }
}

void Player::calTotalScore() {  // ���� ���� ���
  this->score_ = 0;
  this->calG();
  this->calM();
  this->calD();
  this->calP();
}