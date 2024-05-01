#pragma once
#ifndef LONGLONG_H
#define LONGLONG_H

class LongLong {
private:
  long highPart;
  unsigned long lowPart;

public:
  LongLong(long high, unsigned long low);

  // Арифметические операции
  LongLong operator+(const LongLong &other) const;
  LongLong operator-(const LongLong &other) const;
  LongLong operator*(const LongLong &other) const;
  LongLong operator/(const LongLong &other) const;
  LongLong operator%(const LongLong &other) const;

  LongLong operator/(double divisor) const;

  // Методы доступа
  long getHighPart() const;
  unsigned long getLowPart() const;

  // Операции сравнения
  bool operator==(const LongLong &other) const;
  bool operator!=(const LongLong &other) const;
  bool operator<(const LongLong &other) const;
  bool operator<=(const LongLong &other) const;
  bool operator>(const LongLong &other) const;
  bool operator>=(const LongLong &other) const;
};

#endif // LONGLONG_H
