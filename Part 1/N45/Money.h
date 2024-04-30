#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iomanip>
#include <iostream>
#include <map>

class Money {
private:
  std::map<int, int>
      denominations; // Поля-номиналы и количество купюр данного достоинства

public:
  Money(); // Конструктор по умолчанию

  // Методы для работы с купюрами
  void addDenomination(int denomination,
                       int count); // Добавить купюры указанного достоинства
  void removeDenomination(int denomination,
                          int count); // Удалить купюры указанного достоинства
  int getDenominationCount(int denomination)
      const; // Получить количество купюр указанного достоинства

  // Методы для операций с суммами
  Money operator+(const Money &other) const; // Оператор сложения сумм
  Money operator-(const Money &other) const; // Оператор вычитания сумм
  Money operator/(int divisor) const; // Оператор деления суммы на целое число
  Money
  operator/(double divisor) const; // Оператор деления суммы на дробное число
  Money operator*(
      double multiplier) const; // Оператор умножения суммы на дробное число

  // Метод для сравнения сумм
  bool operator==(const Money &other) const; // Оператор равенства
  bool operator!=(const Money &other) const; // Оператор неравенства
  bool operator<(const Money &other) const; // Оператор "меньше"
  bool operator>(const Money &other) const; // Оператор "больше"
  bool operator<=(const Money &other) const; // Оператор "меньше или равно"
  bool operator>=(const Money &other) const; // Оператор "больше или равно"

  // Метод для вывода суммы
  void print() const;
};

#endif // MONEY_H
