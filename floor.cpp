#include "floor.h"

void Floor::reset() { floor_list_.clear(); }

void Floor::add_card(Hwatoo card) { floor_list_.push_back(card); }

void Floor::remove_card(Hwatoo card) {
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    if ((*itor).is_same(card)) {
      floor_list_.erase(itor++);
      return;
    } else {
      itor++;
    }
  }
}

void Floor::print_card_list() {
  for (itor = floor_list_.begin(); itor != floor_list_.end(); ++itor) {
    std::cout << (*itor).getName() << " ";
  }
  std::cout << std::endl;
}

