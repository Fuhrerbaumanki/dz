#include "Fraction.h"
#include <iostream>

Fraction::Fraction(long whole, unsigned short fractional)
    : whole_part(whole), fractional_part(fractional) {}

void Fraction::display() const {
  std::cout << whole_part << " + " << fractional_part << "/100" << std::endl;
}

Fraction Fraction::operator+(const Fraction &other) const {
  long whole_sum = whole_part + other.whole_part;
  unsigned short fractional_sum = fractional_part + other.fractional_part;
  if (fractional_sum >= 100) {
    whole_sum++;
    fractional_sum -= 100;
  }
  return Fraction(whole_sum, fractional_sum);
}

Fraction Fraction::operator-(const Fraction &other) const {
  long whole_diff = whole_part - other.whole_part;
  int fractional_diff = fractional_part - other.fractional_part;
  if (fractional_diff < 0) {
    whole_diff--;
    fractional_diff += 100;
  }
  return Fraction(whole_diff, fractional_diff);
}

Fraction Fraction::operator*(const Fraction &other) const {
  long whole_product = (whole_part * other.whole_part) +
                       (fractional_part * other.fractional_part / 100);
  unsigned short fractional_product =
      (fractional_part * other.whole_part) +
      (other.fractional_part * whole_part) +
      ((fractional_part * other.fractional_part) / 100);
  return Fraction(whole_product, fractional_product);
}

bool Fraction::operator<(const Fraction &other) const {
  return (whole_part < other.whole_part) ||
         (whole_part == other.whole_part &&
          fractional_part < other.fractional_part);
}

bool Fraction::operator==(const Fraction &other) const {
  return (whole_part == other.whole_part) &&
         (fractional_part == other.fractional_part);
}

long Fraction::getWholePart() const { return whole_part; }

unsigned short Fraction::getFractionalPart() const { return fractional_part; }
