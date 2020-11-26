#ifndef HWATOO_H
#define HWATOO_H

#include <string>
#include <vector>

class Hwatoo {
 public:
  explicit Hwatoo(std::string name);
  Hwatoo() = default;
  int getMonth() const;
  std::string getKind() const;
  bool is_same(Hwatoo card);
  void setName(std::string name);
  std::string getName();

 private:
  std::string name_;
  std::string kind_;
};

#endif // HWATOO_H 
