#ifndef LONGLONG_H
#define LONGLONG_H

#include <iostream>

class LongLong {
private:
  long high;
  unsigned long low;

public:
  LongLong(long h = 0, unsigned long l = 0);

  LongLong operator+(const LongLong &other) const;
  LongLong operator-(const LongLong &other) const;
  LongLong operator*(const LongLong &other) const;
  LongLong operator/(const LongLong &other) const;
  LongLong operator%(const LongLong &other) const;

  LongLong &operator<<=(int shift);
  LongLong &operator-=(const LongLong &other);

  bool operator==(const LongLong &other) const;
  bool operator!=(const LongLong &other) const;
  bool operator<(const LongLong &other) const;
  bool operator>(const LongLong &other) const;
  bool operator<=(const LongLong &other) const;
  bool operator>=(const LongLong &other) const;

  friend std::ostream &operator<<(std::ostream &os, const LongLong &ll);
};

#endif // LONGLONG_H
