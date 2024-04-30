#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
  long rubles;
  unsigned char kopecks;

public:
  Money(long rub = 0, unsigned char kop = 0) : rubles(rub), kopecks(kop) {}

  // Методы доступа к полям
  long getRubles() const { return rubles; }
  unsigned char getKopecks() const { return kopecks; }

  // Методы для установки значений полей
  void setRubles(long rub) { rubles = rub; }
  void setKopecks(unsigned char kop) { kopecks = kop; }

  // Операторы для сложения, вычитания, деления и умножения
  Money operator+(const Money &other) const;
  Money operator-(const Money &other) const;
  Money operator/(int divisor) const;
  Money operator/(double divisor) const;
  Money operator*(double multiplier) const;

  // Операторы сравнения
  bool operator==(const Money &other) const;
  bool operator!=(const Money &other) const;
  bool operator<(const Money &other) const;
  bool operator<=(const Money &other) const;
  bool operator>(const Money &other) const;
  bool operator>=(const Money &other) const;

  // Метод вывода суммы на экран
  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};

#endif // MONEY_H
