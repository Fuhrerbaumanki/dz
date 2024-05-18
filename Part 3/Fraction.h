#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
  long intPart;
  unsigned short fracPart;

public:
  Fraction(long intPart = 0, unsigned short fracPart = 0);

  Fraction operator+(const Fraction &other) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator*(const Fraction &other) const;
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;

  void print(std::ostream &os) const;
};

#endif // FRACTION_H
