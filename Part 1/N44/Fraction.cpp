#include "Fraction.h"
#include <cstdint>

Fraction::Fraction() : wholePart(0), fractionPart(0) {}

// Конструктор с параметрами
Fraction::Fraction(int64_t whole, uint16_t fraction)
    : wholePart(whole), fractionPart(fraction) {}

// Методы доступа к полям
int64_t Fraction::getWholePart() const { return wholePart; }
uint16_t Fraction::getFractionPart() const { return fractionPart; }

// Операторы сложения, вычитания и умножения
Fraction Fraction::operator+(const Fraction &other) const {
  Fraction result;
  result.wholePart = wholePart + other.wholePart;
  result.fractionPart = fractionPart + other.fractionPart;
  if (result.fractionPart >= 100) {
    result.wholePart += 1;
    result.fractionPart -= 100;
  }
  return result;
}

Fraction Fraction::operator-(const Fraction &other) const {
  Fraction result;
  result.wholePart = wholePart - other.wholePart;
  result.fractionPart = fractionPart - other.fractionPart;
  if (result.fractionPart < 0) {
    result.wholePart -= 1;
    result.fractionPart += 100;
  }
  return result;
}

Fraction Fraction::operator*(const Fraction &other) const {
  Fraction result;
  result.wholePart = wholePart * other.wholePart;
  result.fractionPart = fractionPart * other.fractionPart / 100;
  return result;
}

// Операторы сравнения
bool Fraction::operator==(const Fraction &other) const {
  return (wholePart == other.wholePart && fractionPart == other.fractionPart);
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator<(const Fraction &other) const {
  if (wholePart != other.wholePart) {
    return wholePart < other.wholePart;
  } else {
    return fractionPart < other.fractionPart;
  }
}

bool Fraction::operator>(const Fraction &other) const {
  return !(*this == other || *this < other);
}

bool Fraction::operator<=(const Fraction &other) const {
  return (*this < other || *this == other);
}

bool Fraction::operator>=(const Fraction &other) const {
  return !(*this < other);
}
