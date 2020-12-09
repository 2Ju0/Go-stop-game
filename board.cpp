#include "board.h"

void Board::gameStart(Deck* deck) {
  std::cout << std::endl
            << "                       < 고스톱 게임을 시작합니다 >"
            << std::endl;
  std::cout << std::endl;
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl
            << std::endl;
  std::cout << " player의 게임 순서를 정한 다음 순서대로 이름을 입력하세요."
            << std::endl
            << std::endl;
  std::cout << " player1의 이름을 설정하세요 >> ";
  std::string name;
  std::cin >> name;
  (*deck).player1.setName(name);
  std::cout << " player1의 이름은 [" << (*deck).player1.getName()
            << "] 입니다." << std::endl
            << std::endl;

  std::cout << " player2의 이름을 설정하세요 >> ";
  std::cin >> name;
  (*deck).player2.setName(name);
  std::cout << " player2의 이름은 [" << (*deck).player2.getName()
            << "] 입니다." << std::endl
            << std::endl;

  std::cout << " player3의 이름을 설정하세요 >> ";
  std::cin >> name;
  (*deck).player3.setName(name);
  std::cout << " player3의 이름은 [" << (*deck).player3.getName()
            << "] 입니다." << std::endl
            << std::endl;
  (*deck).gameStart();
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl
            << std::endl;
  std::cout << "                               "
            << "Game Start" << std::endl
            << std::endl;
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl
            << std::endl;
}

void Board::gameOver() {
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl
            << std::endl;
  std::cout << "                               "
            << "Game Over" << std::endl
            << std::endl;
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl
            << std::endl;
}

void Board::printPlayer(Player player) {
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl;
  std::cout << "                           < " << player.getName()
            << "의 먹은패 >" << std::endl;
  std::cout << " [광]";
  player.my_card_list_.printGList();
  std::cout << " [띠]";
  player.my_card_list_.printDList();
  std::cout << " [멍]";
  player.my_card_list_.printMList();
  std::cout << " [피]";
  player.my_card_list_.printPList();

  std::cout << "---------------------------------------------------------------"
               "---------"
            << std::endl;
  std::cout << " [" << player.getName() << "]의 점수 >> "
            << player.getTotalScore() << "점, go :" << player.getGoCount()
            << "고" << std::endl;
  std::cout << "---------------------------------------------------------------"
               "---------"
            << std::endl;
  std::cout << " [" << player.getName() << "]의 손패 >> ";
  player.printHandList();
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl;
}

void Board::printFloor(Floor floor) {
  std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
               "@@@@@@@@@"
            << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << " 바닥패>> ";
  floor.printCardList();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
               "@@@@@@@@@"
            << std::endl;
  std::cout << "───────────────────────────────────────────────────────────────"
               "────────"
            << std::endl;
}

void Board::line() {
  std::cout << "---------------------------------------------------------------"
               "---------"
            << std::endl;
}

