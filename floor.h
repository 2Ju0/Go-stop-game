#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <vector>

#include "hwatoo.h"

class Floor {
public:
  void addCard(Hwatoo card);
  Hwatoo* removeCard(Hwatoo card);
  bool isEmptyFloorList();
  void printCardList();
  int sameCardCount(Hwatoo card);
  std::vector<Hwatoo> sameCardList(Hwatoo card);

private:
  std::vector<Hwatoo> floor_list_;
  std::vector<Hwatoo>::iterator itor;
};
#endif  // FLOOR_H