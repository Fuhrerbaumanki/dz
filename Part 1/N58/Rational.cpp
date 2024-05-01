#include "Rational.h"

Rational::Rational(LongLong num, LongLong den)
    : numerator(num), denominator(den) {
  reduce(); // Вызываем функцию сокращения при создании объекта
}

LongLong Rational::gcd(LongLong a, LongLong b) const {
  while (b != LongLong(0, 0)) {
    LongLong temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void Rational::reduce() {
  LongLong commonDivisor = gcd(numerator, denominator);
  numerator = numerator / commonDivisor;
  denominator = denominator / commonDivisor;
}

Rational Rational::add(const Rational &other) const {
  Rational result = Rational((numerator * other.denominator) +
                                 (other.numerator * denominator),
                             denominator * other.denominator);
  result.reduce();
  return result;
}

Rational Rational::sub(const Rational &other) const {
  Rational result = Rational((numerator * other.denominator) -
                                 (other.numerator * denominator),
                             denominator * other.denominator);
  result.reduce();
  return result;
}

Rational Rational::mul(const Rational &other) const {
  Rational result =
      Rational(numerator * other.numerator, denominator * other.denominator);
  result.reduce();
  return result;
}

Rational Rational::div(const Rational &other) const {
  Rational result =
      Rational(numerator * other.denominator, denominator * other.numerator);
  result.reduce();
  return result;
}

bool Rational::equal(const Rational &other) const {
  return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Rational::greater(const Rational &other) const {
  return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Rational::less(const Rational &other) const {
  return (numerator * other.denominator) < (other.numerator * denominator);
}
