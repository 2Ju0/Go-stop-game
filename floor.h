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
  void print_card_list();

 private:
  std::list<Hwatoo> floor_list_;
  std::list<Hwatoo>::iterator itor;
};

/*int main() {
  Floor floor;
  floor.add_card(Hwatoo("1광"));
  floor.add_card(Hwatoo("2쌍"));
  floor.add_card(Hwatoo("jocker"));

  floor.remove_card(Hwatoo("jocker"));
  floor.print();

  floor.reset();
  floor.print();
}*/
#endif  // FLOOR_H
