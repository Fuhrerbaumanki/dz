#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <cstdint>

class Fraction {
private:
  int64_t wholePart; // Целая часть (длинное целое со знаком)
  uint16_t fractionPart; // Дробная часть (беззнаковое короткое целое)

public:
  Fraction(); // Конструктор по умолчанию
  Fraction(int64_t whole, uint16_t fraction); // Конструктор с параметрами

  int64_t getWholePart() const; // Метод получения целой части
  uint16_t getFractionPart() const; // Метод получения дробной части

  Fraction operator+(const Fraction &other) const; // Оператор сложения
  Fraction operator-(const Fraction &other) const; // Оператор вычитания
  Fraction operator*(const Fraction &other) const; // Оператор умножения

  bool operator==(const Fraction &other) const; // Оператор равенства
  bool operator!=(const Fraction &other) const; // Оператор неравенства
  bool operator<(const Fraction &other) const; // Оператор "меньше"
  bool operator>(const Fraction &other) const; // Оператор "больше"
  bool operator<=(const Fraction &other) const; // Оператор "меньше или равно"
  bool operator>=(const Fraction &other) const; // Оператор "больше или равно"
};

#endif // FRACTION_H
