#include "Calculator.h"
#include "Fraction.h"

Calculator::Calculator() {}

Fraction Calculator::add(const Fraction &a, const Fraction &b) const {
  LongLong highPart(a.getHighPart() + b.getHighPart(), 0);
  LongLong lowPart(a.getLowPart() + b.getLowPart(), 0);
  return Fraction(highPart, lowPart);
}

Fraction Calculator::subtract(const Fraction &a, const Fraction &b) const {
  // Вычитание дробей
  long long newNumerator = a.getHighPart() * b.getDenominator() -
                           b.getNumerator() * a.getDenominator();
  long long newDenominator = a.getDenominator() * b.getDenominator();
  return Fraction(newNumerator, newDenominator);
}

Fraction Calculator::multiply(const Fraction &a, const Fraction &b) const {
  // Умножение дробей
  long long newNumerator = a.getNumerator() * b.getNumerator();
  long long newDenominator = a.getDenominator() * b.getDenominator();
  return Fraction(newNumerator, newDenominator);
}

Fraction Calculator::divide(const Fraction &a, const Fraction &b) const {
  // Деление дробей
  long long newNumerator = a.getNumerator() * b.getDenominator();
  long long newDenominator = a.getDenominator() * b.getNumerator();
  return Fraction(newNumerator, newDenominator);
}
