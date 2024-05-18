#include "Money.h"
#include <cmath>
#include <stdexcept>

Money::Money(long rubles, unsigned char kopecks)
    : rubles(rubles), kopecks(kopecks) {
  normalize();
}

void Money::normalize() {
  if (kopecks >= 100) {
    rubles += kopecks / 100;
    kopecks %= 100;
  }
}

Money &Money::operator+(const Pair &other) const {
  const Money &otherMoney = dynamic_cast<const Money &>(other);
  long newRubles = rubles + otherMoney.rubles;
  unsigned char newKopecks = kopecks + otherMoney.kopecks;
  return *(new Money(newRubles, newKopecks));
}

Money &Money::operator-(const Pair &other) const {
  const Money &otherMoney = dynamic_cast<const Money &>(other);
  long newRubles = rubles - otherMoney.rubles;
  unsigned char newKopecks = kopecks - otherMoney.kopecks;
  if (newKopecks > kopecks) { // if borrowing is needed
    newRubles -= 1;
    newKopecks += 100;
  }
  return *(new Money(newRubles, newKopecks));
}

Money &Money::operator/(double value) const {
  if (value == 0) {
    throw std::invalid_argument("Division by zero");
  }
  double totalKopecks = (rubles * 100 + kopecks) / value;
  long newRubles = static_cast<long>(totalKopecks) / 100;
  unsigned char newKopecks =
      static_cast<unsigned char>(std::round(totalKopecks)) % 100;
  return *(new Money(newRubles, newKopecks));
}

Money &Money::operator*(double value) const {
  double totalKopecks = (rubles * 100 + kopecks) * value;
  long newRubles = static_cast<long>(totalKopecks) / 100;
  unsigned char newKopecks =
      static_cast<unsigned char>(std::round(totalKopecks)) % 100;
  return *(new Money(newRubles, newKopecks));
}

bool Money::operator==(const Pair &other) const {
  const Money &otherMoney = dynamic_cast<const Money &>(other);
  return rubles == otherMoney.rubles && kopecks == otherMoney.kopecks;
}

bool Money::operator!=(const Pair &other) const { return !(*this == other); }

bool Money::operator<(const Pair &other) const {
  const Money &otherMoney = dynamic_cast<const Money &>(other);
  return (rubles < otherMoney.rubles) ||
         (rubles == otherMoney.rubles && kopecks < otherMoney.kopecks);
}

bool Money::operator>(const Pair &other) const { return other < *this; }

bool Money::operator<=(const Pair &other) const { return !(*this > other); }

bool Money::operator>=(const Pair &other) const { return !(*this < other); }

void Money::print(std::ostream &os) const {
  os << rubles << "," << static_cast<int>(kopecks);
}
