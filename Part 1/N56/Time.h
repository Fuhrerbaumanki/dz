#pragma once
#ifndef TIME_H
#define TIME_H

#include <cmath>
#include <iostream>
#include <string>

class Time {
private:
  int hour;
  int minute;
  int second;

public:
  // Конструкторы
  Time(int h = 0, int m = 0, int s = 0);
  Time(const std::string &time_str);

  // Методы
  int total_seconds() const;
  int difference(const Time &other) const;
  Time operator+(int seconds) const;
  Time operator-(int seconds) const;
  bool operator==(const Time &other) const;
  bool operator<(const Time &other) const;
  bool operator<=(const Time &other) const;
  bool operator>(const Time &other) const;
  bool operator>=(const Time &other) const;
  int to_minutes() const;

  // Метод вывода
  friend std::ostream &operator<<(std::ostream &os, const Time &time);
};

#endif // TIME_H
