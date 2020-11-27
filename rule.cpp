#include "rule.h"

  void Rule::bbuk(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
            Player curr_player, Player player2, Player player3) {
    if (throw_card.is_same(deck_card)) {  // 낸 패와 deck 패가 같은지 검사
      if (floor.same_card_count(throw_card) == 1) {
        std::cout << "뻑 입니다!" << std::endl;
        curr_player.plus_bbuk_count();
      }
    }
  }

  // 따닥 : 자신이 낸 패와 deck 패, 깔린 두 패 모두 같은 종류인 경우
  void Rule::ddadak(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
              Player curr_player, Player player2, Player player3) {
    if (throw_card.is_same(deck_card)) {  // 낸 패와 deck 패가 같은지 검사
      if (floor.same_card_count(throw_card) ==
          2) {  // 바닥에 같은 종류의 카드가 2개인지 검사
        std::cout << "따닥 입니다!" << std::endl;
        curr_player.my_card_list_.add_card(&throw_card);  // 먹은 패로 가져온다
        curr_player.my_card_list_.add_card(&deck_card);  // 먹은패로 가져온다
        std::list<Hwatoo> list = floor.same_card_list(
            throw_card);  // 바닥에서 같은 종류의 카드를 리스트에 저장한다
        for (itor = list.begin(); itor != list.end();
             ++itor) {  // 같은 종류의 카드 리스트를 순회하며
          curr_player.my_card_list_.add_card(
              &(*itor));             // 바닥 패를 먹은 패로 가져온다
          floor.remove_card(*itor);  // 해당 카드는 바닥패에서 제거한다
        }
        this->get_cards_from_others(curr_player, player2, player3);
      }
    }
  }

  // 쪽 : 자신이 낸 패와 deck 패만 짝이 맞을 경우
  void Rule::jjok(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
            Player curr_player, Player player2, Player player3) {
    if (throw_card.is_same(deck_card)) {
      if (floor.same_card_count(throw_card) == 0) {
        curr_player.my_card_list_.add_card(&throw_card);
        curr_player.my_card_list_.add_card(&deck_card);
        this->get_cards_from_others(curr_player, player2, player3);
      }
    }
  }

  void Rule::sseul(Hwatoo throw_card, Hwatoo deck_card, Floor floor,
             Player curr_player, Player player2, Player player3) {
    if (floor.is_empty_floor_list()) {
      this->get_cards_from_others(curr_player, player2, player3);
    }
  }

  void Rule::check_chongtong(Player player) {
    int check_month_;
    std::vector<int> check_count_(13);

    // 손 패에 있는 카드의 월... ex) 1월이면 index 1에 접근
    // check_count_의 index에 해당하는 원소에 +1
    for (itor = player.get_hand_list().begin();
         itor != player.get_hand_list().end(); ++itor) {
      check_month_ = (*itor).getMonth();
      for (int i = 1; i < 13; i++) {
        if (check_month_ == i) {
          check_count_[i]++;
          break;
        }
      }
    }
    for (int i = 1; i < 13; i++) {  // 총통 확인
      if (check_count_[i] == 4) {
        player.is_winner(true);
        break;
      }
    }
  }

  void Rule::get_cards_from_others(Player curr_player, Player player2,
                             Player player3) {
    if (!curr_player.is_empty_hand_list()) {  // 마지막 패가 아니라면 나머지
                                              // player에게 카드를 받는다.
      // 나머지 player는 피 리스트에서 카드를 뺏긴다
      Hwatoo* card1 = player2.my_card_list_.steal_card();
      Hwatoo* card2 = player3.my_card_list_.steal_card();
      curr_player.my_card_list_.add_card(card1);
      curr_player.my_card_list_.add_card(card2);
    }
  }
