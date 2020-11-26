#include <iostream>
#include "player.h"


// pay_point 는 실제 게임에서는 돈을 얼마 내야하는지인데 
// 프로그램에서는 포인트로 돈을 대체

// 이 부분은 이동 가능... main으로 이동 가능성
void cal_bock(Player Winner, Player loser1, Player loser2) {
  // 매개변수로 승자, 패자, 패자 순서대로 입력
  // 박 확인하기
  int pay_point_1 = Winner.get_total_score();
  int pay_point_2 = Winner.get_total_score();

  // 폭탄 점수 처리
  if (Winner.get_bomb_count() == 2) {
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if (Winner.get_bomb_count() == 1) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 3고 이상시 점수처리
  if (Winner.get_go_count() >= 4) {  // 4고 이상 4배 처리
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if (Winner.get_go_count() == 3) {  // 3고 2배 처리
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 광박 계산
  if (Winner.my_card_list_.get_g_list().size() >= 3 &&
      loser1.my_card_list_.get_g_list().size() == 0) {
    pay_point_1 *= 2;
  }
  if (Winner.my_card_list_.get_g_list().size() >= 3 &&
      loser2.my_card_list_.get_g_list().size() == 0) {
    pay_point_2 *= 2;
  }
  // 피박 계산
  if (Winner.my_card_list_.get_p_list().size() >= 10 &&
      loser1.my_card_list_.get_p_list().size() < 6) {
    pay_point_1 *= 2;
  }
  if (Winner.my_card_list_.get_p_list().size() >= 10 &&
      loser2.my_card_list_.get_p_list().size() < 6) {
    pay_point_2 *= 2;
  }
  // 멍박 계산
  if (Winner.my_card_list_.get_m_list().size() >= 7) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 나가리 된 경우 계산
  if (/* 게임이 리셋 되는 경우 (전판이 나가리 된 경우) */) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 고박 계산
  // 상대가 1고 이상을 했지만 다른 사람이 역전을 해서 고를 한 사람이 진 경우
  // 그 사람이 패자들의 점수 모두 계산
  if (loser1.get_go_count() != 0) {
    pay_point_1 += pay_point_2;
    pay_point_2 = 0;
  } else if (loser2.get_go_count() != 0) {
    pay_point_2 += pay_point_1;
    pay_point_1 = 0;
  }
}

