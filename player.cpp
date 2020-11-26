#include "player.h"

Player::Player(std::string name) : player_name_(name) {}  // Constructor

void Player::reset() {  // player ��� ���� �ʱ�ȭ
  this->hand_list_.clear();
  this->go_count_ = 0;
  this->score_ = 0;
}

std::string Player::get_name() { return this->player_name_; }

void Player::add_card(Hwatoo card) {  // plyaer�� ���� ����Ʈ�� ī�� �߰�
  hand_list_.push_back(card);
}

void Player::throw_card(
    Hwatoo card) {  // player�� ���� ����Ʈ���� Ư�� ī�� ����
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    if ((*itor).is_same(card)) {
      hand_list_.erase(itor++);
      return;
    } else {
      itor++;
    }
  }
}

int Player::get_go_count() { return this->go_count_; }  // �� go���� Ȯ��

void Player::plus_go_count() { this->go_count_++; }  // go �� ����

void Player::print_hand_list() {  // player�� ī�� ����Ʈ ���
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

int Player::get_total_score() { return this->score_; }  // player ���� ��ȯ

int Player::get_bbuk_count() { return this->bbuk_count_; }

int Player::get_bomb_count() { return this->bomb_count_; }

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
    //�� 1���� �ٸ� ������ ��2�� ���� ���
  } else if (this->G_point_ == 4 && this->except_point_ == 1) {
    this->score_ += 15;
  } else if (this->G_point_ >= 3) {
    this->score_ = G_point_ + except_point_;
  }
}

void Player::cal_D() {
  std::list<Hwatoo> list = this->my_card_list_.get_d_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    // û�� Ȯ��
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
    // ȫ�� Ȯ��
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

    // �ʴ� Ȯ��
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
  if (this->D_point_ >= 5) {  // �찡 5�� �̻��� ���
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
  if (this->make_godori_ == 3) {  // ���� ���
    this->score_ += 5;
  }
  if (this->M_point_ >= 5) {  // ���� 5�� �̻��� ���
    this->score_ += (this->M_point_ - 4);
  }
}

void Player::cal_P() {
  std::list<Hwatoo> list = this->my_card_list_.get_p_list();
  for (itor = list.begin(); itor != list.end(); ++itor) {
    std::string kind = (*itor).getKind();
    if (kind == "��") {
      this->P_point_ += 2;
    } else {
      this->P_point_ += 1;
    }
    if (this->P_point_ >= 10) {  // �ǰ� 10�� �̻��� ���
      this->score_ += (this->P_point_ - 9);
    }
  }
}

// ������ �κ�
void Player::cal_total_score() { 
  this->score_ = 0;
  this->score_ += this->get_go_count(); // �� ������ ���Ե�
  this->cal_G();
  this->cal_M();
  this->cal_D();
  this->cal_P();
}
// �߰��� �κ�
void Player::check_bomb() {
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    switch ((*itor).getMonth()) {
      case 1:
        check_1++;
        continue;
      case 2:
        check_2++;
        continue;
      case 3:
        check_3++;
        continue;
      case 4:
        check_4++;
        continue;
      case 5:
        check_5++;
        continue;
      case 6:
        check_6++;
        continue;
      case 7:
        check_7++;
        continue;
      case 8:
        check_8++;
        continue;
      case 9:
        check_9++;
        continue;
      case 10:
        check_10++;
        continue;
      case 11:
        check_11++;
        continue;
      case 12:
        check_12++;
        continue;
    }
  }
  bomb_count_ = 0; // �޼ҵ� �����Ҷ� �׻� �ʱ�ȭ
  if (check_1 == 3) bomb_count_++;
  if (check_2 == 3) bomb_count_++;
  if (check_3 == 3) bomb_count_++;
  if (check_4 == 3) bomb_count_++;
  if (check_5 == 3) bomb_count_++;
  if (check_6 == 3) bomb_count_++;
  if (check_7 == 3) bomb_count_++;
  if (check_8 == 3) bomb_count_++;
  if (check_9 == 3) bomb_count_++;
  if (check_10 == 3) bomb_count_++;
  if (check_11 == 3) bomb_count_++;
  if (check_12 == 3) bomb_count_++;
}
// �߰��� �κ�
void Player::check_chongtong() {
  for (itor = hand_list_.begin(); itor != hand_list_.end(); ++itor) {
    switch ((*itor).getMonth()) {
      case 1:
        check_1++;
        continue;
      case 2:
        check_2++;
        continue;
      case 3:
        check_3++;
        continue;
      case 4:
        check_4++;
        continue;
      case 5:
        check_5++;
        continue;
      case 6:
        check_6++;
        continue;
      case 7:
        check_7++;
        continue;
      case 8:
        check_8++;
        continue;
      case 9:
        check_9++;
        continue;
      case 10:
        check_10++;
        continue;
      case 11:
        check_11++;
        continue;
      case 12:
        check_12++;
        continue;
    }
  }
  if (check_1 == 4) winner = true;
  if (check_2 == 4) winner = true;
  if (check_3 == 4) winner = true;
  if (check_4 == 4) winner = true;
  if (check_5 == 4) winner = true;
  if (check_6 == 4) winner = true;
  if (check_7 == 4) winner = true;
  if (check_8 == 4) winner = true;
  if (check_9 == 4) winner = true;
  if (check_10 == 4) winner = true;
  if (check_11 == 4) winner = true;
  if (check_12 == 4) winner = true;
}