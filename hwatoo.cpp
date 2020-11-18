#include <iostream>
#include <vector>

class Hwatoo {
 public:
  Hwatoo(std::string name) : name_(name) {}
  Hwatoo() {}

  int getMonth() const {
    char temp = name_.at(0);
    if (isdigit(temp)) {
      return temp - '0';
    } else if (temp == 'P') {
      return 10;
    } else if (temp == 'D') {
      return 11;
    } else if (temp == 'B') {
      return 12;
    } else {
      return 13;
    }
  }

  std::string getKind() const {
    std::vector<char> charArray(name_.begin(), name_.end());
    charArray.push_back('\0');
    char* charArrayPtr = &charArray[0];
    char* temp = charArrayPtr + 1;
    if (strcmp(temp, "피") == 0) {
      return "피";
    } else if (strcmp(temp, "광") == 0) {
      return "광";
    } else if (strcmp(temp, "멍") == 0) {
      return "멍";
    } else if (strcmp(temp, "띠") == 0) {
      return "띠";
    } else if (strcmp(temp, "쌍") == 0) {
      return "쌍";
    }else {
      return "jocker";
    }
  }

  bool is_same(Hwatoo card) { 
    return (this->getName() == card.getName());
  }

  std::string  getName() { return name_; }

 private:
  std::string name_;
};

/*int main() {
  Hwatoo arr[3] = {Hwatoo("P광"), Hwatoo("jocker"), Hwatoo("1피")};
  for (int i = 0; i < 3; i++) {
    std::cout << arr[i].getMonth() << " " << arr[i].getKind()<< std::endl;
  }
  
}*/
