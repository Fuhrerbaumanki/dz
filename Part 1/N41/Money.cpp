#include "Money.h"
#include <iostream>

// Конструктор по умолчанию
Money::Money() : rubles(0), kopecks(0) {}

// Конструктор с параметрами
Money::Money(long rub, unsigned char kop) : rubles(rub), kopecks(kop) {}

// Метод для вывода денежной суммы на экран
void Money::display() const {
  std::cout << rubles << "," << static_cast<int>(kopecks) << " руб.";
}

// Перегрузка оператора сложения
Money Money::operator+(const Money &m) const {
  long sumRubles = rubles + m.rubles;
  unsigned char sumKopecks = kopecks + m.kopecks;
  if (sumKopecks >= 100) {
    sumRubles++;
    sumKopecks -= 100;
  }
  return Money(sumRubles, sumKopecks);
}

// Перегрузка оператора вычитания
Money Money::operator-(const Money &m) const {
  // Преобразуем обе суммы в копейки
  long total1 = rubles * 100 + kopecks;
  long total2 = m.rubles * 100 + m.kopecks;

  // Вычитаем одну сумму из другой
  long diff = total1 - total2;

  // Проверяем, чтобы результат не был отрицательным
  if (diff < 0) {
    std::cerr << "Ошибка: Результат вычитания дает отрицательную сумму."
              << std::endl;
    return Money(0, 0); // Возвращаем нулевую сумму
  }

  // Разделяем разницу на рубли и копейки
  long resultRubles = diff / 100;
  unsigned char resultKopecks = diff % 100;

  // Возвращаем результат
  return Money(resultRubles, resultKopecks);
}

// Перегрузка оператора деления сумм
Money Money::operator/(int divisor) const {
  long divRubles = rubles / divisor;
  unsigned char divKopecks =
      (rubles % divisor) * 100 / divisor + kopecks / divisor;
  return Money(divRubles, divKopecks);
}

// Перегрузка оператора деления суммы на дробное число
Money Money::operator/(double divisor) const {
  double totalAmount = rubles + kopecks / 100.0;
  totalAmount /= divisor;
  long divRubles = static_cast<long>(totalAmount);
  unsigned char divKopecks =
      static_cast<unsigned char>((totalAmount - divRubles) * 100);
  return Money(divRubles, divKopecks);
}

// Перегрузка оператора сравнения 'меньше'
bool Money::operator<(const Money &m) const {
  if (rubles < m.rubles)
    return true;
  if (rubles == m.rubles && kopecks < m.kopecks)
    return true;
  return false;
}

// Перегрузка оператора сравнения 'больше'
bool Money::operator>(const Money &m) const {
  return !(*this < m) && !(*this == m);
}

// Перегрузка оператора сравнения 'равно'
bool Money::operator==(const Money &m) const {
  return (rubles == m.rubles && kopecks == m.kopecks);
}

long Money::getRubles() const { return rubles; }

unsigned char Money::getKopecks() const { return kopecks; }

Money Money::operator*(double factor) const {
  long totalKopecks = rubles * 100 + kopecks;
  totalKopecks = static_cast<long>(totalKopecks * factor);
  long newRubles = totalKopecks / 100;
  unsigned char newKopecks = totalKopecks % 100;
  return Money(newRubles, newKopecks);
}
