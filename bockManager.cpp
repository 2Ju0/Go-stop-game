#include <iostream>
#include "player.h"


// pay_point �� ���� ���ӿ����� ���� �� �����ϴ����ε� 
// ���α׷������� ����Ʈ�� ���� ��ü

// �� �κ��� �̵� ����... main���� �̵� ���ɼ�
void cal_bock(Player Winner, Player loser1, Player loser2) {
  // �Ű������� ����, ����, ���� ������� �Է�
  // �� Ȯ���ϱ�
  int pay_point_1 = Winner.get_total_score();
  int pay_point_2 = Winner.get_total_score();

  // ��ź ���� ó��
  if (Winner.get_bomb_count() == 2) {
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if (Winner.get_bomb_count() == 1) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 3�� �̻�� ����ó��
  if (Winner.get_go_count() >= 4) {  // 4�� �̻� 4�� ó��
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if (Winner.get_go_count() == 3) {  // 3�� 2�� ó��
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // ���� ���
  if (Winner.my_card_list_.get_g_list().size() >= 3 &&
      loser1.my_card_list_.get_g_list().size() == 0) {
    pay_point_1 *= 2;
  }
  if (Winner.my_card_list_.get_g_list().size() >= 3 &&
      loser2.my_card_list_.get_g_list().size() == 0) {
    pay_point_2 *= 2;
  }
  // �ǹ� ���
  if (Winner.my_card_list_.get_p_list().size() >= 10 &&
      loser1.my_card_list_.get_p_list().size() < 6) {
    pay_point_1 *= 2;
  }
  if (Winner.my_card_list_.get_p_list().size() >= 10 &&
      loser2.my_card_list_.get_p_list().size() < 6) {
    pay_point_2 *= 2;
  }
  // �۹� ���
  if (Winner.my_card_list_.get_m_list().size() >= 7) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // ������ �� ��� ���
  if (/* ������ ���� �Ǵ� ��� (������ ������ �� ���) */) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // ��� ���
  // ��밡 1�� �̻��� ������ �ٸ� ����� ������ �ؼ� �� �� ����� �� ���
  // �� ����� ���ڵ��� ���� ��� ���
  if (loser1.get_go_count() != 0) {
    pay_point_1 += pay_point_2;
    pay_point_2 = 0;
  } else if (loser2.get_go_count() != 0) {
    pay_point_2 += pay_point_1;
    pay_point_1 = 0;
  }
}

