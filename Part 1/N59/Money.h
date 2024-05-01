#pragma once
#ifndef MONEY_H
#define MONEY_H

#include "LongLong.h"
#include <iostream>

class Money {
private:
  LongLong amount;

public:
  Money(long rubles, unsigned long kopecks);
  Money(const LongLong &amount);

  // Методы доступа
  long getRubles() const;
  unsigned long getKopecks() const;

  // Арифметические операции
  Money operator+(const Money &other) const;
  Money operator-(const Money &other) const;
  Money operator/(const Money &other) const;
  Money operator/(double divisor) const;

  // Операции сравнения
  bool operator==(const Money &other) const;
  bool operator!=(const Money &other) const;
  bool operator<(const Money &other) const;
  bool operator<=(const Money &other) const;
  bool operator>(const Money &other) const;
  bool operator>=(const Money &other) const;

  // Перегрузка оператора вывода для удобства
  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};

#endif // MONEY_H
