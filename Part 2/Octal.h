#ifndef OCTAL_H
#define OCTAL_H

#include "Array.h"

class Octal : public Array {
public:
  Octal(int size);
  Octal(const Octal &other);
  ~Octal();

  int setDigit(int index, unsigned char value);
  unsigned char getDigit(int index) const;

  Octal operator+(const Octal &other) const;
  Octal operator-(const Octal &other) const;
  Octal operator*(const Octal &other) const;
  Octal operator/(const Octal &other) const;

  bool operator==(const Octal &other) const;
  bool operator!=(const Octal &other) const;
  bool operator<(const Octal &other) const;
  bool operator>(const Octal &other) const;

  Array *add(const Array &other) const override;
};

#endif // OCTAL_H
