#include <list>

#include "hwatoo.cpp"

class Floor {
 public:
  Floor() {}

  void reset() { card_list.clear(); }

  void add_card(Hwatoo card) { card_list.push_back(card); }

  void remove_card(Hwatoo card) {
    for (itor = card_list.begin(); itor != card_list.end(); ++itor) {
      if ((*itor).is_same(card)) {
        card_list.erase(itor++);
        return;
      } else {
        itor++;
      }
    }
  }

  std::list<Hwatoo> get_card_list() { return this->card_list; }

  void print() {
    for (itor = card_list.begin(); itor != card_list.end(); ++itor) {
      std::cout << (*itor).getName() << " " << std::endl;
    }
  }

 private:
  std::list<Hwatoo> card_list;
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
