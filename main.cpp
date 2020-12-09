#include "board.h"
#include "deck.h"
#include "hwatoo.h"
#include "result.h"
#include "rule.h"

int main() {
  Hwatoo card[48] = {
      Hwatoo("1��"), Hwatoo("1��"), Hwatoo("1��"), Hwatoo("1��"), Hwatoo("2��"),
      Hwatoo("2��"), Hwatoo("2��"), Hwatoo("2��"), Hwatoo("3��"), Hwatoo("3��"),
      Hwatoo("3��"), Hwatoo("3��"), Hwatoo("4��"), Hwatoo("4��"), Hwatoo("4��"),
      Hwatoo("4��"), Hwatoo("5��"), Hwatoo("5��"), Hwatoo("5��"), Hwatoo("5��"),
      Hwatoo("6��"), Hwatoo("6��"), Hwatoo("6��"), Hwatoo("6��"), Hwatoo("7��"),
      Hwatoo("7��"), Hwatoo("7��"), Hwatoo("7��"), Hwatoo("8��"), Hwatoo("8��"),
      Hwatoo("8��"), Hwatoo("8��"), Hwatoo("9��"), Hwatoo("9��"), Hwatoo("9��"),
      Hwatoo("9��"), Hwatoo("P��"), Hwatoo("P��"), Hwatoo("P��"), Hwatoo("P��"),
      Hwatoo("D��"), Hwatoo("D��"), Hwatoo("D��"), Hwatoo("D��"), Hwatoo("B��"),
      Hwatoo("B��"), Hwatoo("B��"), Hwatoo("B��") };
  Hwatoo* free = new Hwatoo("FREE");

  Deck deck = Deck(card);    // Deck ��ü ����
  Board board = Board();     // Board ��ü ����
  Rule rule = Rule();        // Rule ��ü ����
  Result result = Result();  // Result ��ü ����
  std::vector<Player*> player_list;
  int card_index;
  std::vector<Hwatoo>::iterator itor;
  bool end = false;

  player_list.push_back(&deck.player1);
  player_list.push_back(&deck.player2);
  player_list.push_back(&deck.player3);
  // game ����
  board.gameStart(&deck);
  std::cout << " ������ ���, �� ���° �������� �����ּ���!" << std::endl;
  std::cout << " ���Ⱑ �ƴ� ���, 0�� �Է����ּ���! >> ";
  std::cin >> result.number_of_game_;
  std::cout << std::endl;

  // ���� Ȯ��
  rule.checkChongtong(&deck.player1);
  rule.checkChongtong(&deck.player2);
  rule.checkChongtong(&deck.player3);

  if (deck.player1.winner_) {
    std::cout << " [" << deck.player1.getName() << "]�� �������� �¸��߽��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player2.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player3.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
  }
  else if (deck.player2.winner_) {
    std::cout << " [" << deck.player2.getName() << "]�� �������� �¸��߽��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player1.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player3.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
  }
  else if (deck.player2.winner_) {
    std::cout << " [" << deck.player3.getName() << "]�� �������� �¸��߽��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player1.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
    std::cout << " [" << deck.player2.getName() << "]�� 3 point�� �ҽ��ϴ�."
      << std::endl;
  }

  while (1) {
    if (deck.player1.winner_ || deck.player2.winner_ || deck.player3.winner_ ||
      end) {
      // ���ڰ� ������ ��� or ���ڰ� �������� ���� ���
      board.gameOver();
      break;
    }

    for (int i = 0; i < 3; i++) {
      Player* other2_p_ = player_list[(i + 2) % 3];
      Player* other1_p_ = player_list[(i + 1) % 3];
      Player* now_p_ = player_list[i % 3];

      board.printPlayer(*other2_p_);
      board.printPlayer(*other1_p_);
      board.printFloor(deck.floor);
      board.printPlayer(*now_p_);

      std::cout << " [" << (*player_list[i]).getName()
        << "]�� �����Դϴ�. �� ī�� ��ȣ�� �Է����ּ���." << std::endl
        << " �ݵ�� ���ڰ� �ƴ� ���ڷ� �Է��ϼ��� >> ";
      std::cin >> card_index;  // player�� ���ϴ� ī�� ������ ����
      std::cout << std::endl;

      // �Է��� ���ڰ� ��ȿ���� Ȯ��
      while (1) {
        if (card_index >= 0 &&
          card_index < player_list[i]->getHandList().size()) {
          break;
        }
        else {
          std::cout << " ��ȿ�� ���ڸ� �Է����� �ʾҽ��ϴ�. �� ī�� ��ȣ�� "
            "�ٽ� �Է����ּ���. >> ";
          std::cin >> card_index;
        }
      }

      // ���� ī�带 pick_card�� ����
      Hwatoo pick_card = now_p_->getHandList()[card_index];
      std::cout << " ���� ī��: [" << pick_card.getMonth()
        << pick_card.getKind() << "]" << std::endl
        << std::endl;

      // player�� deck���� ī�� ������ ������ �ܰ�
      Hwatoo deck_card = deck.deck_list_.front();
      deck.deck_list_.pop();
      std::cout << " deck���� ������ ī��: [" << deck_card.getMonth()
        << deck_card.getKind() << "]" << std::endl
        << std::endl;

      // FREE ī�带 �� ���
      if (pick_card.isSame(*free)) {
        player_list[i]->removeCard(pick_card);
        std::cout << " (�ƹ��͵� ���� �ʰ�, draw�� �ൿ�� ";
        if (deck.floor.sameCardCount(deck_card) == 0) {
          std::cout << "������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
            << std::endl
            << std::endl;
          deck.floor.addCard(deck_card);
        }
        else if (deck.floor.sameCardCount(deck_card) == 1) {
          std::cout << "������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
            << std::endl
            << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
        }
        else if (deck.floor.sameCardCount(deck_card) == 2) {
          std::cout << "������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
            << std::endl
            << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
        }
        else if (deck.floor.sameCardCount(deck_card) == 3) {
          std::cout << "������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
            << std::endl
            << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloor(&deck, now_p_, &deck_card);
          rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
          std::cout << " �����մϴ�!! �ѹ��� 4���� �԰� 1�徿 ����ɴϴ�."
            << std::endl
            << std::endl;
        }
        continue;
      }

      if (now_p_->sameCardCountInHandList(pick_card) ==
        3) {  // ���п� ���� ������ ī�尡 3�� �ִ� ���
        std::cout << " (���п� ���� ������ ī�尡 3���� �־�" << std::endl
          << std::endl;
        player_list[i]->removeCard(pick_card);
        now_p_->plusShakingCount();  // ��� ī��Ʈ �ø���

        if (deck.floor.sameCardCount(pick_card) == 1) {  // ��ź���� ���� ���
          std::cout << " ��ź���� ���� ���,";
          // �ѹ��� 3���� �����Ƿ� FREE ī�� 2���� �԰� �ȴ�.
          now_p_->addCard(*free);
          now_p_->addCard(*free);
          // �� ī�带 ���� �з� �̵� ��Ų��.
          now_p_->my_card_list_.eatCard(&pick_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
          rule.getCardsFromHand(player_list[i], &pick_card);

          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << "������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(deck_card);

            // ��ź���� ���� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! �ѹ��� 4���� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;

          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);

            // ��ź���� ���� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! �ѹ��� 4���� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);

            // ��ź���� ���� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! �ѹ��� 4���� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " �� ī�尡 �ٴ� ī��� 3�� ���� ���)" << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);

            // ��ź���� ���� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! �ѹ��� 8���� �԰� 2�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
        else {
          std::cout << " ��ź���� ���� �ʰ� 1�徿 ���� ����," << std::endl
            << std::endl;
          if (deck.floor.sameCardCount(deck_card) == 0) {
            if (pick_card.isSame(deck_card)) {  // �� ��Ȳ
              std::cout << " ������ ���� ī�尡 �տ��� �� ī��� ���� ���)"
                << std::endl
                << std::endl;
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              // ������ ���� 1�徿 �������
              rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
              std::cout << " �� �Դϴ�!! 1�徿 ����ɴϴ�." << std::endl
                << std::endl;
            }
            else {  // � ī�嵵 ��ġ���� �ʴ� ���
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
            }
          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
      }
      else {
        player_list[i]->removeCard(pick_card);
        if (deck.floor.sameCardCount(pick_card) == 1) {
          std::cout << " (�տ��� ���� ī�尡 �ٴ� ī��� 1�� ����,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            if (pick_card.isSame(deck_card)) {  // �� ��Ȳ
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
              now_p_->plusBbukCount();
              std::cout << " ���Դϴ�!!" << std::endl;
            }
            else {
              now_p_->my_card_list_.eatCard(&pick_card);
              rule.getCardsFromFloor(&deck, now_p_, &pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            }
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! �ѹ��� 4���� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
        else if (deck.floor.sameCardCount(pick_card) == 2) {
          std::cout << " (�տ��� ���� ī�尡 �ٴ� ī��� 2�� ����,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            if (pick_card.isSame(deck_card)) {  // ������ ���
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloor(&deck, now_p_, &deck_card);
              // �������� ���� 1�徿 �������
              rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
              std::cout << " �����Դϴ�!! ���徿 ����ɴϴ�." << std::endl
                << std::endl;
            }
            else {
              now_p_->my_card_list_.eatCard(&pick_card);
              rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            }
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �ѹ��� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
        else if (deck.floor.sameCardCount(pick_card) == 3) {
          std::cout << " (�տ��� ���� ī�尡 �ٴ� ī��� 3�� ����,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
            // �ٴ� 3���� �տ��� ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �ѹ��� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            // �ٴ� 3���� �տ��� ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �ѹ��� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            // �ٴ� 3���� �տ��� ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �ѹ��� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
              << std::endl
              << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // �ٴ� 3���� �տ��� ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 8���� �ѹ��� �԰� 2�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
        else if (deck.floor.sameCardCount(pick_card) == 0) {
          // �� ī�尡 �ٴ� �п� �ƹ��͵� ��ġ���� �ʴ� ���
          std::cout << " (�տ��� ���� ī�尡 �ٴ� ī��� 0�� ����,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 0�� ���� ���)"
              << std::endl
              << std::endl;
            if (pick_card.isSame(deck_card)) {  // �� ��Ȳ
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              // ������ ���� 1�徿 �������
              if (now_p_->getHandList().size() != 0) {
                rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
                std::cout << " �� �Դϴ�!! 1�徿 ����ɴϴ�." << std::endl;
              }
            }
            else {  // � ī�嵵 ��ġ���� �ʴ� ���
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
            }
          }
          else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 1�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 2�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          }
          else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " ������ ���� ī�尡 �ٴ� ī��� 3�� ���� ���)"
              << std::endl
              << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // �ٴ� 3���� ������ ���� ī�尡 ��ġ�� 1�徿 �������
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " �����մϴ�!! 4���� �ѹ��� �԰� 1�徿 ����ɴϴ�."
              << std::endl
              << std::endl;
          }
        }
      }

      // ������ Ȯ���ϴ� ���
      if (deck.floor.isEmptyFloorList() && now_p_->getHandList().size() != 0) {
        rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
        std::cout << " ���Դϴ�!! 1�徿 ����ɴϴ�." << std::endl;
      }

      (*now_p_).calTotalScore();
      (*other1_p_).calTotalScore();
      (*other2_p_).calTotalScore();
      int keep_going = 0;

      if (now_p_->getHandList().size() == 0) {
        // go stop ���ñǾ��� �׳� �¸��ϴ� ���
        if ((now_p_->getGoCount() == 0 && now_p_->getTotalScore() >= 3) ||
          (now_p_->getGoCount() > 0 &&
            now_p_->getTotalScore() > now_p_->getTempScore())) {
          std::cout << std::endl;
          board.printPlayer(*other2_p_);
          board.printPlayer(*other1_p_);
          board.printFloor(deck.floor);
          board.printPlayer(*now_p_);
          now_p_->winner_ = true;
          std::cout << " [" << now_p_->getName() << "]�� �¸��Ͽ����ϴ�."
            << std::endl
            << std::endl;
          result.result(now_p_, other1_p_, other2_p_);
          break;
        }
      }
      else {
        // GO STOP ���ñ��� ����� ���
        if ((now_p_->getGoCount() == 0 && now_p_->getTotalScore() >= 3) ||
          (now_p_->getGoCount() > 0 &&
            now_p_->getTotalScore() > now_p_->getTempScore())) {
          std::cout << std::endl;
          board.printPlayer(*other2_p_);
          board.printPlayer(*other1_p_);
          board.printFloor(deck.floor);
          board.printPlayer(*now_p_);
          // Go�� ���� STOP�� ���� ����
          std::cout << " [1]GO �� �Ͻðڽ��ϱ�? " << std::endl;
          std::cout << " [2]STOP �� �Ͻðڽ��ϱ�? " << std::endl;
          std::cin >> keep_going;
          // �Է��� ���ڰ� ��ȿ���� Ȯ��
          while (1) {
            if (keep_going > 0 && keep_going < 3) {
              break;
            }
            else {
              std::cout << " ��ȿ�� ���ڸ� �Է����� �ʾҽ��ϴ�. ��ȣ�� �ٽ� "
                "�Է����ּ���.>> ";
              std::cin >> keep_going;
            }
          }
          if (keep_going == 1) {
            now_p_->plusGoCount();
            now_p_->setTempScore(now_p_->getTotalScore());
          }
          else {
            now_p_->winner_ = true;
            std::cout << " [" << now_p_->getName() << "]�� �¸��Ͽ����ϴ�."
              << std::endl
              << std::endl;
            result.result(now_p_, other1_p_, other2_p_);
            break;
          }
        }
      }

      if (now_p_->getHandList().size() == 0 &&
        other1_p_->getHandList().size() == 0 &&
        other2_p_->getHandList().size() == 0) {
        board.printPlayer(*other2_p_);
        board.printPlayer(*other1_p_);
        board.printFloor(deck.floor);
        board.printPlayer(*now_p_);
        std::cout << " ���ڰ� �������� �ʾҽ��ϴ�." << std::endl;
        std::cout << " ���Ⱑ �ʿ��մϴ�." << std::endl;
        std::cout << " ���α׷��� �ٽ� �������ּ���." << std::endl;
        end = true;
        break;
      }
    }
  }
}