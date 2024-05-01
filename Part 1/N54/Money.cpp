#include "Money.h"
#include <iomanip>
#include <iostream>

Money::Money(long whole, unsigned short fractional)
    : amount(whole, fractional) {}

Money::Money(const Fraction &fraction) : amount(fraction) {}

void Money::display() const {
  std::cout << amount.getWholePart() << "," << std::setw(2) << std::setfill('0')
            << amount.getFractionalPart() << std::endl;
}

Money Money::operator+(const Money &other) const {
  return Money(amount + other.amount);
}

Money Money::operator-(const Money &other) const {
  return Money(amount - other.amount);
}

Money Money::operator/(const Money &other) const {
  // Assuming fractional part is less than 100
  double result = static_cast<double>(amount.getWholePart() * 100 +
                                      amount.getFractionalPart()) /
                  static_cast<double>(other.amount.getWholePart() * 100 +
                                      other.amount.getFractionalPart());
  long whole = static_cast<long>(result);
  unsigned short fractional =
      static_cast<unsigned short>((result - whole) * 100);
  return Money(whole, fractional);
}

Money Money::operator/(double divisor) const {
  // Assuming fractional part is less than 100
  double result = static_cast<double>(amount.getWholePart() * 100 +
                                      amount.getFractionalPart()) /
                  divisor;
  long whole = static_cast<long>(result);
  unsigned short fractional =
      static_cast<unsigned short>((result - whole) * 100);
  return Money(whole, fractional);
}

Money Money::operator*(double multiplier) const {
  // Assuming fractional part is less than 100
  double result = static_cast<double>(amount.getWholePart() * 100 +
                                      amount.getFractionalPart()) *
                  multiplier;
  long whole = static_cast<long>(result / 100);
  unsigned short fractional = static_cast<unsigned short>(result) % 100;
  return Money(whole, fractional);
}

bool Money::operator<(const Money &other) const {
  return amount < other.amount;
}

bool Money::operator==(const Money &other) const {
  return amount == other.amount;
}
