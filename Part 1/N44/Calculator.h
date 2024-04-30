#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Fraction.h"

class Calculator {
private:
  Fraction fraction;

public:
  Calculator(); // Конструктор по умолчанию

  void setFraction(int64_t whole,
                   uint16_t fractionPart); // Метод установки значения дроби
  void add(const Fraction &other);      // Дробь + дробь
  void subtract(const Fraction &other); // Дробь - дробь
  void multiply(const Fraction &other); // Дробь * дробь
  void printFraction() const;           // Вывод дроби
};

#endif // CALCULATOR_H
