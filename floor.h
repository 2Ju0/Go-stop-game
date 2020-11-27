#ifndef FLOOR_H
#define FLOOR_H

#include <list>
#include <iostream>

#include "hwatoo.h"

class Floor {
 public:
  void reset();
  void add_card(Hwatoo card);
  void remove_card(Hwatoo card);
  bool is_empty_floor_list();
  void print_card_list();
  int same_card_count(Hwatoo card);
  std::list<Hwatoo> same_card_list(Hwatoo card);

 private:
  std::list<Hwatoo> floor_list_;
  std::list<Hwatoo>::iterator itor;
};
#endif  // FLOOR_H
