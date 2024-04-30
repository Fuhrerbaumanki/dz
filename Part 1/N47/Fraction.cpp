#include "Fraction.h"

Fraction::Fraction(const LongLong &whole, double fractional)
    : wholePart(whole), fractionalPart(fractional) {}

Fraction Fraction::operator+(const Fraction &other) const {
  LongLong newWhole = wholePart + other.wholePart;
  double newFractional = fractionalPart + other.fractionalPart;

  // Обработка переноса из дробной части в целую
  if (newFractional >= 1.0) {
    newWhole = newWhole + LongLong(0, 1);
    newFractional -= 1.0;
  }

  return Fraction(newWhole, newFractional);
}

Fraction Fraction::operator-(const Fraction &other) const {
  LongLong newWhole = wholePart - other.wholePart;
  double newFractional = fractionalPart - other.fractionalPart;

  // Обработка заимствования из целой части
  if (newFractional < 0.0) {
    newWhole = newWhole - LongLong(0, 1);
    newFractional += 1.0;
  }

  return Fraction(newWhole, newFractional);
}

Fraction Fraction::operator*(const Fraction &other) const {
  LongLong newWhole = wholePart * other.wholePart;
  double newFractional = fractionalPart * other.fractionalPart;
  newWhole = newWhole + LongLong(0, static_cast<unsigned long>(newFractional));

  // Обработка переноса из дробной части в целую
  newWhole = newWhole + LongLong(0, static_cast<unsigned long>(newFractional));
  newFractional -= static_cast<unsigned long>(newFractional);

  return Fraction(newWhole, newFractional);
}

Fraction Fraction::operator/(const Fraction &other) const {
  if (other.wholePart == LongLong(0, 0) && other.fractionalPart == 0.0) {
    // Деление на ноль
    return Fraction(LongLong(0, 0), 0.0);
  }

  double divisor = other.wholePart.getHighPart() +
                   other.wholePart.getLowPart() * 1e-9 + other.fractionalPart;
  double quotient = (wholePart.getHighPart() + wholePart.getLowPart() * 1e-9 +
                     fractionalPart) /
                    divisor;

  LongLong newWhole(static_cast<long>(quotient), 0);
  double newFractional = quotient - newWhole.getHighPart();

  return Fraction(newWhole, newFractional);
}

bool Fraction::operator==(const Fraction &other) const {
  return wholePart == other.wholePart && fractionalPart == other.fractionalPart;
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
  if (wholePart < other.wholePart)
    return true;
  if (wholePart > other.wholePart)
    return false;
  return fractionalPart < other.fractionalPart;
}

bool Fraction::operator<=(const Fraction &other) const {
  return (*this < other) || (*this == other);
}

bool Fraction::operator>(const Fraction &other) const {
  return !(*this <= other);
}

bool Fraction::operator>=(const Fraction &other) const {
  return !(*this < other);
}

long Fraction::getHighPart() const { return wholePart.getHighPart(); }
unsigned long Fraction::getLowPart() const { return wholePart.getLowPart(); }
