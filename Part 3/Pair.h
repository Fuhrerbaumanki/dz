#pragma once
#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
public:
  virtual ~Pair(){};
  virtual Pair &operator+(const Pair &other) const = 0;
  virtual Pair &operator-(const Pair &other) const = 0;
  virtual Pair &operator/(double value) const = 0;
  virtual Pair &operator*(double value) const = 0;
  virtual bool operator==(const Pair &other) const = 0;
  virtual bool operator!=(const Pair &other) const = 0;
  virtual bool operator<(const Pair &other) const = 0;
  virtual bool operator>(const Pair &other) const = 0;
  virtual bool operator<=(const Pair &other) const = 0;
  virtual bool operator>=(const Pair &other) const = 0;

  virtual void print(std::ostream &os) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Pair &pair) {
    pair.print(os);
    return os;
  }
};

#endif // PAIR_H
