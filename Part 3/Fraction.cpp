#include "Fraction.h"

Fraction::Fraction(long intPart, unsigned short fracPart)
    : intPart(intPart), fracPart(fracPart) {}

Fraction Fraction::operator+(const Fraction &other) const {
  long newIntPart = intPart + other.intPart;
  unsigned short newFracPart = fracPart + other.fracPart;
  if (newFracPart >= 10000) {
    newIntPart++;
    newFracPart -= 10000;
  }
  return Fraction(newIntPart, newFracPart);
}

Fraction Fraction::operator-(const Fraction &other) const {
  long newIntPart = intPart - other.intPart;
  unsigned short newFracPart = fracPart - other.fracPart;
  if (newFracPart < 0) {
    newIntPart--;
    newFracPart += 10000;
  }
  return Fraction(newIntPart, newFracPart);
}

Fraction Fraction::operator*(const Fraction &other) const {
  long newIntPart = intPart * other.intPart;
  unsigned long long tempFracPart =
      static_cast<unsigned long long>(fracPart) * other.fracPart;
  newIntPart += tempFracPart / 10000;
  unsigned short newFracPart = tempFracPart % 10000;
  return Fraction(newIntPart, newFracPart);
}

bool Fraction::operator==(const Fraction &other) const {
  return intPart == other.intPart && fracPart == other.fracPart;
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
  if (intPart != other.intPart)
    return intPart < other.intPart;
  return fracPart < other.fracPart;
}

bool Fraction::operator>(const Fraction &other) const {
  if (intPart != other.intPart)
    return intPart > other.intPart;
  return fracPart > other.fracPart;
}

bool Fraction::operator<=(const Fraction &other) const {
  return !(*this > other);
}

bool Fraction::operator>=(const Fraction &other) const {
  return !(*this < other);
}

void Fraction::print(std::ostream &os) const {
  os << intPart << '.' << fracPart;
}
