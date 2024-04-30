#include "Money.h"
#include <iostream>
#include <map>

Money Money::operator+(const Money &other) const {
  Money result(rubles + other.rubles, kopeks + other.kopeks);
  for (auto &denom : denominations) {
    result.denominations[denom.first] =
        denominations.at(denom.first) + other.denominations.at(denom.first);
  }
  if (result.kopeks >= 100) {
    result.rubles++;
    result.kopeks -= 100;
  }
  return result;
}

// Перегруженный оператор вычитания
Money Money::operator-(const Money &other) const {
  Money result(rubles - other.rubles, kopeks - other.kopeks);
  for (auto &denom : denominations) {
    result.denominations[denom.first] =
        denominations.at(denom.first) - other.denominations.at(denom.first);
  }
  if (result.kopeks < 0) {
    result.rubles--;
    result.kopeks += 100;
  }
  return result;
}

// Перегруженный оператор умножения
Money Money::operator*(float multiplier) const {
  int totalRubles = static_cast<int>(rubles * multiplier);
  int totalKopeks = static_cast<int>(kopeks * multiplier);
  if (totalKopeks >= 100) {
    totalRubles += totalKopeks / 100;
    totalKopeks %= 100;
  }
  Money result(totalRubles, totalKopeks);
  for (auto &denom : denominations) {
    result.denominations[denom.first] =
        static_cast<int>(denominations.at(denom.first) * multiplier);
  }
  return result;
}

// Перегруженный оператор деления
Money Money::operator/(float divisor) const {
  int totalRubles = static_cast<int>(rubles / divisor);
  int totalKopeks = static_cast<int>(kopeks / divisor);
  if (totalKopeks >= 100) {
    totalRubles += totalKopeks / 100;
    totalKopeks %= 100;
  }
  Money result(totalRubles, totalKopeks);
  for (auto &denom : denominations) {
    result.denominations[denom.first] =
        static_cast<int>(denominations.at(denom.first) / divisor);
  }
  return result;
}

// Перегруженный оператор сравнения равенства
bool Money::operator==(const Money &other) const {
  return (rubles == other.rubles && kopeks == other.kopeks &&
          denominations == other.denominations);
}

// Перегруженный оператор сравнения неравенства
bool Money::operator!=(const Money &other) const { return !(*this == other); }

// Перегруженный оператор сравнения меньше
bool Money::operator<(const Money &other) const {
  return (rubles < other.rubles ||
          (rubles == other.rubles && kopeks < other.kopeks));
}

// Перегруженный оператор сравнения меньше или равно
bool Money::operator<=(const Money &other) const {
  return (*this < other || *this == other);
}

// Перегруженный оператор сравнения больше
bool Money::operator>(const Money &other) const { return !(*this <= other); }

// Перегруженный оператор сравнения больше или равно
bool Money::operator>=(const Money &other) const { return !(*this < other); }

// Функция для вывода денежной суммы
std::ostream &operator<<(std::ostream &os, const Money &money) {
  os << money.rubles << ",";
  if (money.kopeks < 10)
    os << "0"; // Добавление ведущего нуля для копеек с одной цифрой
  os << money.kopeks;
  return os;
}
