#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
  long rubles;
  unsigned char kopecks;

public:
  // Конструктор
  Money(long rub = 0, unsigned char kop = 0);

  // Метод для вывода денежной суммы
  void display() const;

  // Перегрузка оператора сложения
  Money operator+(const Money &other) const;

  // Перегрузка оператора вычитания
  Money operator-(const Money &other) const;

  // Перегрузка оператора умножения на дробное число
  Money operator*(double multiplier) const;

  // Перегрузка оператора деления на дробное число
  Money operator/(double divisor) const;
};

#endif // MONEY_H
