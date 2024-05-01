#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include "LongLong.h"

class Rational {
private:
  LongLong numerator;
  LongLong denominator;

  // Приватная функция для нахождения наибольшего общего делителя
  LongLong gcd(LongLong a, LongLong b) const;

  // Приватная функция для сокращения дроби
  void reduce();

public:
  Rational(LongLong num, LongLong den);

  // Арифметические операции
  Rational add(const Rational &other) const;
  Rational sub(const Rational &other) const;
  Rational mul(const Rational &other) const;
  Rational div(const Rational &other) const;

  // Операции сравнения
  bool equal(const Rational &other) const;
  bool greater(const Rational &other) const;
  bool less(const Rational &other) const;
};

#endif // RATIONAL_H
