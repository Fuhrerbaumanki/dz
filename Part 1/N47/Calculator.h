#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Fraction.h"

class Calculator {
public:
  // Сложение
  Fraction add(const Fraction &a, const Fraction &b) const;

  // Вычитание
  Fraction subtract(const Fraction &a, const Fraction &b) const;

  // Умножение
  Fraction multiply(const Fraction &a, const Fraction &b) const;

  // Деление
  Fraction divide(const Fraction &a, const Fraction &b) const;
};

#endif // CALCULATOR_H
