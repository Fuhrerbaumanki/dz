#pragma once
#ifndef BITSTRING_H
#define BITSTRING_H

#include <iostream>

class BitString {
private:
  unsigned long high;
  unsigned long low;

public:
  BitString(unsigned long value = 0);
  ~BitString();

  // Перегрузка операторов
  BitString operator&(const BitString &other) const;
  BitString operator|(const BitString &other) const;
  BitString operator^(const BitString &other) const;
  BitString operator~() const;
  BitString operator<<(int n) const;
  BitString operator>>(int n) const;

  unsigned long getLow() const;
  unsigned long getHigh() const;

  // Методы
  void shiftLeft(int n);
  void shiftRight(int n);

  // Перегрузка оператора вывода
  friend std::ostream &operator<<(std::ostream &os, const BitString &bs);
};

#endif // BITSTRING_H
