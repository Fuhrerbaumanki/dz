#pragma once
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
  long whole_part;
  unsigned short fractional_part;

public:
  Fraction(long whole, unsigned short fractional);

  long getWholePart() const;
  unsigned short getFractionalPart() const;

  void display() const;

  Fraction operator+(const Fraction &other) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator*(const Fraction &other) const;

  bool operator<(const Fraction &other) const;
  bool operator==(const Fraction &other) const;
};

#endif // FRACTION_H
