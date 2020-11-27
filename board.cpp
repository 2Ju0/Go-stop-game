#include "board.h"

void Board::printBoard(Floor floor, Player player1, Player player2,
                       Player player3) {
  std::cout << "바닥패 : ";
  floor.print_card_list();
  std::cout << player1.get_name() << " 의 먹은패 : " << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << "[광]";
  player1.my_card_list_.print_g_list();
  std::cout << "[띠]";
  player1.my_card_list_.print_d_list();
  std::cout << "[멍]";
  player1.my_card_list_.print_m_list();
  std::cout << "[피]";
  player1.my_card_list_.print_p_list();
  std::cout << player1.get_name() << "의 점수 : " << player1.get_total_score()
            << "점, ";
  std::cout << "go : " << player1.get_go_count() << "고" << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << player1.get_name() << " 의 손패 : ";
  player1.print_hand_list();
  std::cout << std::endl;

  std::cout << player2.get_name() << "의 먹은패 : " << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << "[광]";
  player2.my_card_list_.print_g_list();
  std::cout << "[띠]";
  player2.my_card_list_.print_d_list();
  std::cout << "[멍]";
  player2.my_card_list_.print_m_list();
  std::cout << "[피]";
  player2.my_card_list_.print_p_list();
  std::cout << player2.get_name() << "의 점수 : " << player2.get_total_score()
            << "점, ";
  std::cout << "go : " << player2.get_go_count() << "고" << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << player2.get_name() << " 의 손패 : ";
  player2.print_hand_list();
  std::cout << std::endl;
  std::cout << player3.get_name() << "의 먹은패 : " << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << "[광]";
  player3.my_card_list_.print_g_list();
  std::cout << "[띠]";
  player3.my_card_list_.print_d_list();
  std::cout << "[멍]";
  player3.my_card_list_.print_m_list();
  std::cout << "[피]";
  player3.my_card_list_.print_p_list();
  std::cout << player3.get_name() << "의 점수 : " << player3.get_total_score()
            << "점, ";
  std::cout << "go : " << player3.get_go_count() << "고" << std::endl;
  std::cout << "==========================" << std::endl;
  std::cout << player3.get_name() << " 의 손패 : ";
  player3.print_hand_list();
  std::cout << std::endl;
}
