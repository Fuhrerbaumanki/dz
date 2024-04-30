#pragma once
#ifndef MONEY_H
#define MONEY_H

class Money {
private:
  long rubles;
  unsigned char kopecks;

public:
  Money(); // Конструктор по умолчанию
  Money(long rub, unsigned char kop); // Конструктор с параметрами

  void display() const; // Метод для вывода денежной суммы на экран

  Money operator+(const Money &m) const; // Перегрузка оператора сложения
  Money operator-(const Money &m) const; // Перегрузка оператора вычитания
  Money operator/(int divisor) const; // Перегрузка оператора деления сумм
  Money operator/(double divisor)
      const; // Перегрузка оператора деления суммы на дробное число
  bool
  operator<(const Money &m) const; // Перегрузка оператора сравнения 'меньше'
  bool
  operator>(const Money &m) const; // Перегрузка оператора сравнения 'больше'
  bool
  operator==(const Money &m) const; // Перегрузка оператора сравнения 'равно'
};

#endif // MONEY_H
