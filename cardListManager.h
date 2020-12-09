#ifndef CARDLISTMANAGER_H
#define CARDLISTMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "hwatoo.h"

class CardListManager {
public:
  std::vector<Hwatoo> getGList();
  std::vector<Hwatoo> getMList();
  std::vector<Hwatoo> getDList();
  std::vector<Hwatoo> getPList();
  void eatCard(Hwatoo* card);
  void removePCard();
  Hwatoo* stealCard();
  void printGList();
  void printMList();
  void printDList();
  void printPList();

private:
  std::vector<Hwatoo> g_list_;
  std::vector<Hwatoo> m_list_;
  std::vector<Hwatoo> d_list_;
  std::vector<Hwatoo> p_list_;
  std::vector<Hwatoo>::iterator itor;
};
#endif  // CARDLISTMANAGER_H