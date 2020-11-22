#ifndef CARDLISTMANAGER_H
#define CARDLISTMANAGER_H

#include <list>
#include <iostream>

#include "hwatoo.h"

class CardListManager {
 public:
  std::list<Hwatoo> get_g_list();
  std::list<Hwatoo> get_m_list();
  std::list<Hwatoo> get_d_list();
  std::list<Hwatoo> get_p_list();
  std::list<Hwatoo> get_d_list();
  void reset();
  void add_card(Hwatoo card);
  void remove_card(Hwatoo card);
  void print_card_list(std::string kind);

 private:
  std::list<Hwatoo> g_list_;         
  std::list<Hwatoo> m_list_;        
  std::list<Hwatoo> d_list_;         
  std::list<Hwatoo> p_list_;        
  std::list<Hwatoo> j_list_;         
  std::list<Hwatoo>::iterator itor;  
};
#endif  // CARDLISTMANAGER_H

