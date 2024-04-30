#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include "LongLong.h"

class Fraction {
private:
  LongLong wholePart;
  double fractionalPart;

public:
  // Конструктор
  Fraction(const LongLong &whole = LongLong(0, 0), double fractional = 0.0);

  // Арифметические операции
  Fraction operator+(const Fraction &other) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator*(const Fraction &other) const;
  Fraction operator/(const Fraction &other) const;

  // Методы доступа
  long getHighPart() const;
  unsigned long getLowPart() const;

  // Операции сравнения
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator>(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
};

#endif // FRACTION_H
