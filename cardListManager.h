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
  std::list<Hwatoo> get_list_type(Hwatoo card);
  void add_card(Hwatoo* card);
  Hwatoo* steal_card();
  void remove_card(Hwatoo* card);
  void print_g_list();
  void print_m_list();
  void print_d_list();
  void print_p_list();

 private:
  std::list<Hwatoo> g_list_;         
  std::list<Hwatoo> m_list_;        
  std::list<Hwatoo> d_list_;         
  std::list<Hwatoo> p_list_;           
  std::list<Hwatoo>::iterator itor;  
};
#endif  // CARDLISTMANAGER_H

