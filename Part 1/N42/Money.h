#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <map>

class Money {
private:
  std::map<int, int> denominations; // Карта для хранения номиналов и их кол-ва
  int kopeks; // Копейки
  int rubles; // Рубли

public:
  // Конструктор
  Money(int rubles = 0, int kopeks = 0);

  // Перегрузка операторов
  Money operator+(const Money &other) const;
  Money operator-(const Money &other) const;
  Money operator*(float multiplier) const;
  Money operator/(float divisor) const;
  bool operator==(const Money &other) const;
  bool operator!=(const Money &other) const;
  bool operator<(const Money &other) const;
  bool operator<=(const Money &other) const;
  bool operator>(const Money &other) const;
  bool operator>=(const Money &other) const;

  // Вывод денежной суммы
  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};

#endif // MONEY_H
