#pragma once
#ifndef MONEY_H
#define MONEY_H

#include "Fraction.h"

class Money {
private:
  Fraction amount;

public:
  Money(long whole, unsigned short fractional);
  Money(const Fraction &fraction);

  void display() const;

  Money operator+(const Money &other) const;
  Money operator-(const Money &other) const;
  Money operator/(const Money &other) const;
  Money operator/(double divisor) const;
  Money operator*(double multiplier) const;

  bool operator<(const Money &other) const;
  bool operator==(const Money &other) const;
};

#endif // MONEY_H
