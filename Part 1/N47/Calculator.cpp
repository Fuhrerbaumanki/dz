#include "Calculator.h"
#include <stdexcept>

Fraction Calculator::add(const Fraction &a, const Fraction &b) const {
  return a + b;
}

// Вычитание
Fraction Calculator::subtract(const Fraction &a, const Fraction &b) const {
  return a - b;
}

// Умножение
Fraction Calculator::multiply(const Fraction &a, const Fraction &b) const {
  return a * b;
}

// Деление
Fraction Calculator::divide(const Fraction &a, const Fraction &b) const {
  if (b.getHighPart() == 0 && b.getHighPart() == 0.0) {
    // Обработка деления на ноль
    throw std::invalid_argument("Деление на 0");
  }
  return a / b;
}
