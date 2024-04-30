#include "Money.h"
#include <iostream>

// Конструктор
Money::Money(long rubles, unsigned char kopecks)
    : rubles(rubles), kopecks(kopecks) {}

// Метод для вывода денежной суммы
void Money::display() const {
  std::cout << rubles << "," << static_cast<int>(kopecks);
}

// Перегрузка оператора сложения
Money Money::operator+(const Money &other) const {
  long totalRubles = rubles + other.rubles;
  int totalKopecks = kopecks + other.kopecks;
  if (totalKopecks >= 100) {
    totalRubles++;
    totalKopecks -= 100;
  }
  return Money(totalRubles, static_cast<unsigned char>(totalKopecks));
}

// Перегрузка оператора вычитания
Money Money::operator-(const Money &other) const {
  long totalRubles = rubles - other.rubles;
  int totalKopecks = kopecks - other.kopecks;
  if (totalKopecks < 0) {
    totalRubles--;
    totalKopecks += 100;
  }
  return Money(totalRubles, static_cast<unsigned char>(totalKopecks));
}

// Перегрузка оператора умножения на дробное число
Money Money::operator*(double multiplier) const {
  double totalAmount = rubles + kopecks / 100.0;
  totalAmount *= multiplier;
  long newRubles = static_cast<long>(totalAmount);
  unsigned char newKopecks =
      static_cast<unsigned char>((totalAmount - newRubles) * 100);
  return Money(newRubles, newKopecks);
}

// Перегрузка оператора деления на дробное число
Money Money::operator/(double divisor) const {
  if (divisor == 0) {
    std::cerr << "Error: Division by zero\n";
    return Money();
  }
  double totalAmount = rubles + kopecks / 100.0;
  totalAmount /= divisor;
  long newRubles = static_cast<long>(totalAmount);
  unsigned char newKopecks =
      static_cast<unsigned char>((totalAmount - newRubles) * 100);
  return Money(newRubles, newKopecks);
}
