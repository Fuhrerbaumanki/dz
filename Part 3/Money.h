#ifndef MONEY_H
#define MONEY_H

#include "Pair.h"

class Money : public Pair {
private:
  long rubles;
  unsigned char kopecks;

  void normalize();

public:
  Money(long rubles = 0, unsigned char kopecks = 0);

  Money &operator+(const Pair &other) const override;
  Money &operator-(const Pair &other) const override;
  Money &operator/(double value) const override;
  Money &operator*(double value) const override;
  bool operator==(const Pair &other) const override;
  bool operator!=(const Pair &other) const override;
  bool operator<(const Pair &other) const override;
  bool operator>(const Pair &other) const override;
  bool operator<=(const Pair &other) const override;
  bool operator>=(const Pair &other) const override;

  void print(std::ostream &os) const override;
};

#endif // MONEY_H
