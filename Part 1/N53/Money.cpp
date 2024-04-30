#include "Money.h"

Money Money::operator+(const Money &other) const {
  long total_rubles = rubles + other.rubles;
  int total_kopecks = kopecks + other.kopecks;

  if (total_kopecks >= 100) {
    total_rubles++;
    total_kopecks -= 100;
  }

  return Money(total_rubles, static_cast<unsigned char>(total_kopecks));
}

Money Money::operator-(const Money &other) const {
  long total_rubles = rubles - other.rubles;
  int total_kopecks = kopecks - other.kopecks;

  if (total_kopecks < 0) {
    total_rubles--;
    total_kopecks += 100;
  }

  return Money(total_rubles, static_cast<unsigned char>(total_kopecks));
}

Money Money::operator/(int divisor) const {
  long total_rubles = rubles / divisor;
  int total_kopecks = (rubles % divisor) * 100 / divisor + kopecks / divisor;
  return Money(total_rubles, static_cast<unsigned char>(total_kopecks));
}

Money Money::operator/(double divisor) const {
  double total_value = (rubles * 100 + kopecks) / divisor;
  long total_rubles = total_value / 100;
  int total_kopecks = total_value - total_rubles * 100;
  return Money(total_rubles, static_cast<unsigned char>(total_kopecks));
}

Money Money::operator*(double multiplier) const {
  double total_value = (rubles * 100 + kopecks) * multiplier;
  long total_rubles = total_value / 100;
  int total_kopecks = total_value - total_rubles * 100;
  return Money(total_rubles, static_cast<unsigned char>(total_kopecks));
}

bool Money::operator==(const Money &other) const {
  return (rubles == other.rubles) && (kopecks == other.kopecks);
}

bool Money::operator!=(const Money &other) const { return !(*this == other); }

bool Money::operator<(const Money &other) const {
  return rubles < other.rubles ||
         (rubles == other.rubles && kopecks < other.kopecks);
}

bool Money::operator<=(const Money &other) const {
  return *this < other || *this == other;
}

bool Money::operator>(const Money &other) const { return !(*this <= other); }

bool Money::operator>=(const Money &other) const { return !(*this < other); }

std::ostream &operator<<(std::ostream &os, const Money &money) {
  os << money.getRubles() << "," << (money.getKopecks() < 10 ? "0" : "")
     << static_cast<int>(money.getKopecks());
  return os;
}
