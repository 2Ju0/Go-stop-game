#include "result.h"

void Result::result(Player* Winner, Player* loser1, Player* loser2) {
  // 매개변수로 승자, 패자, 패자 순서대로 입력
  int winner_score = (*Winner).getTotalScore() + (*Winner).getGoCount();
  int pay_point_1 = winner_score;
  int pay_point_2 = winner_score;

  // 폭탄 점수 처리
  if ((*Winner).getShakingCount() == 2) {
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if ((*Winner).getShakingCount() == 1) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 3고 이상시 점수처리
  if ((*Winner).getGoCount() >= 4) {  // 4고 이상 4배 처리
    pay_point_1 *= 4;
    pay_point_2 *= 4;
  } else if ((*Winner).getGoCount() == 3) {  // 3고 2배 처리
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 광박 계산
  if ((*Winner).my_card_list_.getGList().size() >= 3 &&
      (*loser1).my_card_list_.getGList().size() == 0) {
    pay_point_1 *= 2;
  }
  if ((*Winner).my_card_list_.getGList().size() >= 3 &&
      (*loser2).my_card_list_.getGList().size() == 0) {
    pay_point_2 *= 2;
  }
  // 피박 계산 >> 룰 예외 처리 필요
  if ((*Winner).my_card_list_.getPList().size() >= 10 &&
      (*loser1).my_card_list_.getPList().size() < 6) {
    pay_point_1 *= 2;
  }
  if ((*Winner).my_card_list_.getPList().size() >= 10 &&
      (*loser2).my_card_list_.getPList().size() < 6) {
    pay_point_2 *= 2;
  }
  // 멍박 계산
  if ((*Winner).my_card_list_.getMList().size() >= 7) {
    pay_point_1 *= 2;
    pay_point_2 *= 2;
  }
  // 재경기 인 경우 계산
  if (number_of_game_ > 0) {
    pay_point_1 *= (2 * number_of_game_);
    pay_point_2 *= (2 * number_of_game_);
  }
  // 고박 계산
  if ((*loser1).getGoCount() != 0) {
    pay_point_1 += pay_point_2;
    pay_point_2 = 0;
  } else if ((*loser2).getGoCount() != 0) {
    pay_point_2 += pay_point_1;
    pay_point_1 = 0;
  }
  std::cout << std::endl;
  std::cout << " [" << Winner->getName() << "]가 총 " << winner_score
            << " 점을 획득했습니다." << std::endl;
  std::cout << " [" << loser1->getName() << "]가 " << pay_point_1
            << " point를 잃습니다." << std::endl;
  std::cout << " [" << loser2->getName() << "]가 " << pay_point_2
            << " point를 잃습니다." << std::endl;
}

