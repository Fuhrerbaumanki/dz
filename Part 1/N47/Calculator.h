// Calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Fraction.h"

class Calculator {
private:
  Fraction scalar;

public:
  // Конструктор
  Calculator();

  // Арифметические операции
  Fraction add(const Fraction &a, const Fraction &b) const;
  Fraction subtract(const Fraction &a, const Fraction &b) const;
  Fraction multiply(const Fraction &a, const Fraction &b) const;
  Fraction divide(const Fraction &a, const Fraction &b) const;
};

#endif // CALCULATOR_H
