#include "board.h"
#include "deck.h"
#include "hwatoo.h"
#include "result.h"
#include "rule.h"

int main() {
  Hwatoo card[48] = {
      Hwatoo("1광"), Hwatoo("1띠"), Hwatoo("1피"), Hwatoo("1피"), Hwatoo("2멍"),
      Hwatoo("2띠"), Hwatoo("2피"), Hwatoo("2피"), Hwatoo("3광"), Hwatoo("3띠"),
      Hwatoo("3피"), Hwatoo("3피"), Hwatoo("4멍"), Hwatoo("4띠"), Hwatoo("4피"),
      Hwatoo("4피"), Hwatoo("5멍"), Hwatoo("5띠"), Hwatoo("5피"), Hwatoo("5피"),
      Hwatoo("6멍"), Hwatoo("6띠"), Hwatoo("6피"), Hwatoo("6피"), Hwatoo("7멍"),
      Hwatoo("7띠"), Hwatoo("7피"), Hwatoo("7피"), Hwatoo("8광"), Hwatoo("8멍"),
      Hwatoo("8피"), Hwatoo("8피"), Hwatoo("9쌍"), Hwatoo("9띠"), Hwatoo("9피"),
      Hwatoo("9피"), Hwatoo("P멍"), Hwatoo("P띠"), Hwatoo("P피"), Hwatoo("P피"),
      Hwatoo("D광"), Hwatoo("D피"), Hwatoo("D피"), Hwatoo("D쌍"), Hwatoo("B광"),
      Hwatoo("B멍"), Hwatoo("B띠"), Hwatoo("B쌍")};
  Hwatoo* free = new Hwatoo("FREE");

  Deck deck = Deck(card);    // Deck 객체 생성
  Board board = Board();     // Board 객체 생성
  Rule rule = Rule();        // Rule 객체 생성
  Result result = Result();  // Result 객체 생성
  std::vector<Player*> player_list;
  int card_index;
  std::vector<Hwatoo>::iterator itor;
  bool end = false;

  player_list.push_back(&deck.player1);
  player_list.push_back(&deck.player2);
  player_list.push_back(&deck.player3);
  // game 시작
  board.gameStart(&deck);
  std::cout << " 재경기인 경우, 몇 경기째 재경기인지 적어주세요!" << std::endl;
  std::cout << " 재경기가 아닌 경우, 0을 입력해주세요! >> ";
  std::cin >> result.number_of_game_;
  std::cout << std::endl;

  // 총통 확인
  rule.checkChongtong(&deck.player1);
  rule.checkChongtong(&deck.player2);
  rule.checkChongtong(&deck.player3);

  if (deck.player1.winner_) {
    std::cout << " [" << deck.player1.getName() << "]가 총통으로 승리했습니다."
              << std::endl;
    std::cout << " [" << deck.player2.getName() << "]가 3 point를 잃습니다."
              << std::endl;
    std::cout << " [" << deck.player3.getName() << "]가 3 point를 잃습니다."
              << std::endl;
  } else if (deck.player2.winner_) {
    std::cout << " [" << deck.player2.getName() << "]가 총통으로 승리했습니다."
              << std::endl;
    std::cout << " [" << deck.player1.getName() << "]가 3 point를 잃습니다."
              << std::endl;
    std::cout << " [" << deck.player3.getName() << "]가 3 point를 잃습니다."
              << std::endl;
  } else if (deck.player2.winner_) {
    std::cout << " [" << deck.player3.getName() << "]가 총통으로 승리했습니다."
              << std::endl;
    std::cout << " [" << deck.player1.getName() << "]가 3 point를 잃습니다."
              << std::endl;
    std::cout << " [" << deck.player2.getName() << "]가 3 point를 잃습니다."
              << std::endl;
  }

  while (1) {
    if (deck.player1.winner_ || deck.player2.winner_ || deck.player3.winner_ ||
        end) {
      // 승자가 결정된 경우 or 승자가 결정되지 않은 경우
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
                << "]의 순서입니다. 낼 카드 번호를 입력해주세요." << std::endl
                << " 반드시 문자가 아닌 숫자로 입력하세요 >> ";
      std::cin >> card_index;  // player가 원하는 카드 한장을 낸다
      std::cout << std::endl;

      // 입력한 숫자가 유효한지 확인
      while (1) {
        if (card_index >= 0 &&
            card_index < player_list[i]->getHandList().size()) {
          break;
        } else {
          std::cout << " 유효한 숫자를 입력하지 않았습니다. 낼 카드 번호를 "
                       "다시 입력해주세요. >> ";
          std::cin >> card_index;
        }
      }

      // 뽑은 카드를 pick_card에 저장
      Hwatoo pick_card = now_p_->getHandList()[card_index];
      std::cout << " 뽑은 카드: [" << pick_card.getMonth()
                << pick_card.getKind() << "]" << std::endl
                << std::endl;

      // player가 deck에서 카드 한장을 뒤집는 단계
      Hwatoo deck_card = deck.deck_list_.front();
      deck.deck_list_.pop();
      std::cout << " deck에서 뒤집은 카드: [" << deck_card.getMonth()
                << deck_card.getKind() << "]" << std::endl
                << std::endl;

      // FREE 카드를 낸 경우
      if (pick_card.isSame(*free)) {
        player_list[i]->removeCard(pick_card);
        std::cout << " (아무것도 내지 않고, draw만 행동해 ";
        if (deck.floor.sameCardCount(deck_card) == 0) {
          std::cout << "덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                    << std::endl
                    << std::endl;
          deck.floor.addCard(deck_card);
        } else if (deck.floor.sameCardCount(deck_card) == 1) {
          std::cout << "덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                    << std::endl
                    << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
        } else if (deck.floor.sameCardCount(deck_card) == 2) {
          std::cout << "덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                    << std::endl
                    << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
        } else if (deck.floor.sameCardCount(deck_card) == 3) {
          std::cout << "덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                    << std::endl
                    << std::endl;
          now_p_->my_card_list_.eatCard(&deck_card);
          rule.getCardsFromFloor(&deck, now_p_, &deck_card);
          rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
          std::cout << " 감사합니다!! 한번에 4장을 먹고 1장씩 뺏어옵니다."
                    << std::endl
                    << std::endl;
        }
        continue;
      }

      if (now_p_->sameCardCountInHandList(pick_card) ==
          3) {  // 손패에 같은 종류의 카드가 3장 있는 경우
        std::cout << " (손패에 같은 종류의 카드가 3개가 있어" << std::endl
                  << std::endl;
        player_list[i]->removeCard(pick_card);
        now_p_->plusShakingCount();  // 흔들 카운트 올리기

        if (deck.floor.sameCardCount(pick_card) == 1) {  // 폭탄으로 내는 경우
          std::cout << " 폭탄으로 내는 경우,";
          // 한번에 3개를 냈으므로 FREE 카드 2개를 먹게 된다.
          now_p_->addCard(*free);
          now_p_->addCard(*free);
          // 낸 카드를 먹은 패로 이동 시킨다.
          now_p_->my_card_list_.eatCard(&pick_card);
          rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
          // 손 패에서 같은 월 카드 찾기 위한 리스트 생성
          rule.getCardsFromHand(player_list[i], &deck_card);

          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << "덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(deck_card);

            // 폭탄으로 인한 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 한번에 4장을 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;

          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);

            // 폭탄으로 인한 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 한번에 4장을 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);

            // 폭탄으로 인한 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 한번에 4장을 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱 카드가 바닥 카드와 3개 같은 경우)" << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);

            // 폭탄으로 인한 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 한번에 8장을 먹고 2장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        } else {
          std::cout << " 폭탄으로 내지 않고 1장씩 따로 내고," << std::endl
                    << std::endl;
          if (deck.floor.sameCardCount(deck_card) == 0) {
            if (pick_card.isSame(deck_card)) {  // 쪽 상황
              std::cout << " 덱에서 뽑은 카드가 손에서 낸 카드와 같은 경우)"
                        << std::endl
                        << std::endl;
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              // 쪽으로 인한 1장씩 뺏어오기
              rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
              std::cout << " 쪽 입니다!! 1장씩 뺏어옵니다." << std::endl
                        << std::endl;
            } else {  // 어떤 카드도 일치하지 않는 경우
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
            }
          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        }
      } else {
        player_list[i]->removeCard(pick_card);
        if (deck.floor.sameCardCount(pick_card) == 1) {
          std::cout << " (손에서 뽑은 카드가 바닥 카드와 1개 같고,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            if (pick_card.isSame(deck_card)) {  // 뻑 상황
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
              now_p_->plusBbukCount();
              std::cout << " 뻑입니다!!" << std::endl;
            } else {
              now_p_->my_card_list_.eatCard(&pick_card);
              rule.getCardsFromFloor(&deck, now_p_, &pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            }
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 한번에 4장을 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        } else if (deck.floor.sameCardCount(pick_card) == 2) {
          std::cout << " (손에서 뽑은 카드가 바닥 카드와 2개 같고,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            if (pick_card.isSame(deck_card)) {  // 따닥인 경우
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloor(&deck, now_p_, &deck_card);
              // 따닥으로 인한 1장씩 뺏어오기
              rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
              std::cout << " 따닥입니다!! 한장씩 뺏어옵니다." << std::endl
                        << std::endl;
            } else {
              now_p_->my_card_list_.eatCard(&pick_card);
              rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            }
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 한번에 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        } else if (deck.floor.sameCardCount(pick_card) == 3) {
          std::cout << " (손에서 뽑은 카드가 바닥 카드와 3개 같고,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            deck.floor.addCard(deck_card);
            // 바닥 3개와 손에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 한번에 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            // 바닥 3개와 손에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 한번에 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
            // 바닥 3개와 손에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 한번에 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                      << std::endl
                      << std::endl;
            now_p_->my_card_list_.eatCard(&pick_card);
            rule.getCardsFromFloor(&deck, now_p_, &pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // 바닥 3개와 손에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 8장을 한번에 먹고 2장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        } else if (deck.floor.sameCardCount(pick_card) == 0) {
          // 낸 카드가 바닥 패와 아무것도 일치하지 않는 경우
          std::cout << " (손에서 뽑은 카드가 바닥 카드와 0개 같고,";
          if (deck.floor.sameCardCount(deck_card) == 0) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 0개 같은 경우)"
                      << std::endl
                      << std::endl;
            if (pick_card.isSame(deck_card)) {  // 쪽 상황
              now_p_->my_card_list_.eatCard(&pick_card);
              now_p_->my_card_list_.eatCard(&deck_card);
              // 쪽으로 인한 1장씩 뺏어오기
              if (now_p_->getHandList().size() != 0) {
                rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
                std::cout << " 쪽 입니다!! 1장씩 뺏어옵니다." << std::endl;
              }
            } else {  // 어떤 카드도 일치하지 않는 경우
              deck.floor.addCard(pick_card);
              deck.floor.addCard(deck_card);
            }
          } else if (deck.floor.sameCardCount(deck_card) == 1) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 1개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 2) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 2개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloorWithBreak(&deck, now_p_, &deck_card);
          } else if (deck.floor.sameCardCount(deck_card) == 3) {
            std::cout << " 덱에서 뽑은 카드가 바닥 카드와 3개 같은 경우)"
                      << std::endl
                      << std::endl;
            deck.floor.addCard(pick_card);
            now_p_->my_card_list_.eatCard(&deck_card);
            rule.getCardsFromFloor(&deck, now_p_, &deck_card);
            // 바닥 3개와 덱에서 뽑은 카드가 일치해 1장씩 뺏어오기
            rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
            std::cout << " 감사합니다!! 4장을 한번에 먹고 1장씩 뺏어옵니다."
                      << std::endl
                      << std::endl;
          }
        }
      }

      // 쓸인지 확인하는 경우
      if (deck.floor.isEmptyFloorList() && now_p_->getHandList().size() != 0) {
        rule.getCardsFromOthers(now_p_, other1_p_, other2_p_);
        std::cout << " 쓸입니다!! 1장씩 뺏어옵니다." << std::endl;
      }

      (*now_p_).calTotalScore();
      (*other1_p_).calTotalScore();
      (*other2_p_).calTotalScore();
      int keep_going = 0;

      if (now_p_->getShakingCount() == 3) {
        now_p_->winner_ = true;
        std::cout << " [" << now_p_->getName() << "]가 뻑 3번으로 승리했습니다."
                  << std::endl;
        std::cout << " [" << other1_p_->getName() << "]가 3 point를 잃습니다."
                  << std::endl;
        std::cout << " [" << other2_p_->getName() << "]가 3 point를 잃습니다."
                  << std::endl;
        break;
      }

      if (now_p_->getHandList().size() == 0) {
        // go stop 선택권없이 그냥 승리하는 경우
        if ((now_p_->getGoCount() == 0 && now_p_->getTotalScore() >= 3) ||
            (now_p_->getGoCount() > 0 &&
             now_p_->getTotalScore() > now_p_->getTempScore())) {
          std::cout << std::endl;
          board.printPlayer(*other2_p_);
          board.printPlayer(*other1_p_);
          board.printFloor(deck.floor);
          board.printPlayer(*now_p_);
          now_p_->winner_ = true;
          std::cout << " [" << now_p_->getName() << "]가 승리하였습니다."
                    << std::endl
                    << std::endl;
          result.result(now_p_, other1_p_, other2_p_);
          break;
        }
      } else {
        // GO STOP 선택권이 생기는 경우
        if ((now_p_->getGoCount() == 0 && now_p_->getTotalScore() >= 3) ||
            (now_p_->getGoCount() > 0 &&
             now_p_->getTotalScore() > now_p_->getTempScore())) {
          std::cout << std::endl;
          board.printPlayer(*other2_p_);
          board.printPlayer(*other1_p_);
          board.printFloor(deck.floor);
          board.printPlayer(*now_p_);
          // Go를 할지 STOP을 할지 선택
          std::cout << " [1]GO 를 하시겠습니까? " << std::endl;
          std::cout << " [2]STOP 를 하시겠습니까? ";
          std::cin >> keep_going;
          // 입력한 숫자가 유효한지 확인
          while (1) {
            if (keep_going > 0 && keep_going < 3) {
              break;
            } else {
              std::cout << " 유효한 숫자를 입력하지 않았습니다. 번호를 다시 "
                           "입력해주세요.>> ";
              std::cin >> keep_going;
            }
          }
          if (keep_going == 1) {
            now_p_->plusGoCount();
            now_p_->setTempScore(now_p_->getTotalScore());
          } else {
            now_p_->winner_ = true;
            std::cout << " [" << now_p_->getName() << "]가 승리하였습니다."
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
        std::cout << " 승자가 결정되지 않았습니다." << std::endl;
        std::cout << " 재경기가 필요합니다." << std::endl;
        std::cout << " 프로그램을 다시 실행해주세요." << std::endl;
        end = true;
        break;
      }
    }
  }
}
