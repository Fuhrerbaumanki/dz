#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
  unsigned int year;
  unsigned int month;
  unsigned int day;

public:
  // Конструкторы
  Date();
  Date(unsigned int y, unsigned int m, unsigned int d);
  Date(const std::string &dateStr);
  Date(const Date &other);

  // Методы установки даты
  void setDate(unsigned int y, unsigned int m, unsigned int d);
  void setDate(const std::string &dateStr);

  // Метод вывода даты
  void printDate() const;

  // Методы для работы с датами
  Date addDays(unsigned int numDays) const;
  Date subtractDays(unsigned int numDays) const;
  bool isLeapYear() const;
  unsigned int daysInMonth(unsigned int year, unsigned int month) const;
  unsigned int getYear() const;
  unsigned int getMonth() const;
  unsigned int getDay() const;
  int compare(const Date &other) const;
  int daysBetween(const Date &other) const;

private:
  // Приватный метод для вычисления Юлианского дня
  long int julianDay() const;
};

#endif // DATE_H
