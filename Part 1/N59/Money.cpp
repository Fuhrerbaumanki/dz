#include "Money.h"

Money::Money(long rubles, unsigned long kopecks) : amount(rubles, kopecks) {}

Money::Money(const LongLong &amount) : amount(amount) {}

// Арифметические операции
Money Money::operator+(const Money &other) const {
  return Money(amount + other.amount);
}

Money Money::operator-(const Money &other) const {
  return Money(amount - other.amount);
}

Money Money::operator/(const Money &other) const {
  return Money(amount / other.amount);
}

Money Money::operator/(double divisor) const { return Money(amount / divisor); }

// Операции сравнения
bool Money::operator==(const Money &other) const {
  return amount == other.amount;
}

bool Money::operator!=(const Money &other) const { return !(*this == other); }

bool Money::operator<(const Money &other) const {
  return amount < other.amount;
}

bool Money::operator<=(const Money &other) const {
  return amount <= other.amount;
}

bool Money::operator>(const Money &other) const {
  return amount > other.amount;
}

bool Money::operator>=(const Money &other) const {
  return amount >= other.amount;
}

// Перегрузка оператора вывода для удобства
std::ostream &operator<<(std::ostream &os, const Money &money) {
  os << money.getRubles() << ',' << money.getKopecks();
  return os;
}
