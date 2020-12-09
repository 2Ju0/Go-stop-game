#include "hwatoo.h"
#include <iostream>

Hwatoo::Hwatoo(std::string name) : name_(name) {
  std::vector<char> charArray(name_.begin(), name_.end());
  charArray.push_back('\0');
  char* charArrayPtr = &charArray[0];
  char* temp = charArrayPtr + 1;
  if (strcmp(temp, "피") == 0) {
    this->kind_ = "피";
  } else if (strcmp(temp, "광") == 0) {
    this->kind_ = "광";
  } else if (strcmp(temp, "멍") == 0) {
    this->kind_ = "멍";
  } else if (strcmp(temp, "띠") == 0) {
    this->kind_ = "띠";
  } else if (strcmp(temp, "쌍") == 0) {
    this->kind_ = "쌍";
  }
}

int Hwatoo::getMonth() const {
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

std::string Hwatoo::getKind() const { return this->kind_; }

bool Hwatoo::isSame(Hwatoo card) {
  return (this->getMonth() == card.getMonth());
}

std::string Hwatoo::getName() { return name_; }
