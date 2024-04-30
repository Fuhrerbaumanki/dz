#include "Money.h"

Money::Money() {
  // Инициализируем все номиналы нулями
  denominations[1] = 0;
  denominations[2] = 0;
  denominations[5] = 0;
  denominations[10] = 0;
  denominations[50] = 0;
  denominations[100] = 0;
  denominations[500] = 0;
  denominations[1000] = 0;
  denominations[5000] = 0;
}

void Money::addDenomination(int denomination, int count) {
  denominations[denomination] += count;
}

void Money::removeDenomination(int denomination, int count) {
  if (denominations[denomination] >= count) {
    denominations[denomination] -= count;
  } else {
    std::cerr << "Не хватает купюр " << denomination << std::endl;
  }
}

int Money::getDenominationCount(int denomination) const {
  return denominations.at(denomination);
}

Money Money::operator+(const Money &other) const {
  Money result;
  for (const auto &pair : denominations) {
    result.denominations[pair.first] =
        pair.second + other.denominations.at(pair.first);
  }
  return result;
}

Money Money::operator-(const Money &other) const {
  Money result;
  for (const auto &pair : denominations) {
    result.denominations[pair.first] =
        pair.second - other.denominations.at(pair.first);
  }
  return result;
}

Money Money::operator/(int divisor) const {
  Money result;
  for (const auto &pair : denominations) {
    result.denominations[pair.first] = pair.second / divisor;
  }
  return result;
}

Money Money::operator/(double divisor) const {
  Money result;
  for (const auto &pair : denominations) {
    result.denominations[pair.first] = static_cast<int>(pair.second / divisor);
  }
  return result;
}

Money Money::operator*(double multiplier) const {
  Money result;
  for (const auto &pair : denominations) {
    result.denominations[pair.first] =
        static_cast<int>(pair.second * multiplier);
  }
  return result;
}

bool Money::operator==(const Money &other) const {
  return denominations == other.denominations;
}

bool Money::operator!=(const Money &other) const { return !(*this == other); }

bool Money::operator<(const Money &other) const {
  return denominations < other.denominations;
}

bool Money::operator>(const Money &other) const {
  return denominations > other.denominations;
}

bool Money::operator<=(const Money &other) const {
  return denominations <= other.denominations;
}

bool Money::operator>=(const Money &other) const {
  return denominations >= other.denominations;
}

void Money::print() const {
  std::cout << "Деньги: ";
  for (const auto &pair : denominations) {
    if (pair.first >= 100) {
      std::cout << pair.first / 100 << "." << std::setw(2) << std::setfill('0')
                << pair.first % 100;
    } else {
      std::cout << pair.first;
    }
    std::cout << " rubles: " << pair.second << " ";
  }
  std::cout << std::endl;
}
