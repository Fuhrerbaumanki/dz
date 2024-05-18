#ifndef HEX_H
#define HEX_H

#include "Array.h"

class Hex : public Array {
public:
  Hex(int size);
  Hex(const Hex &hex);
  ~Hex();

  int setDigit(int index, unsigned char value);
  unsigned char getDigit(int index) const;

  Hex operator+(const Hex &hex) const;
  Hex operator-(const Hex &hex) const;
  Hex operator*(const Hex &hex) const;
  Hex operator/(const Hex &hex) const;

  bool operator==(const Hex &hex) const;
  bool operator!=(const Hex &hex) const;
  bool operator<(const Hex &hex) const;
  bool operator>(const Hex &hex) const;

  Array *add(const Array &other) const override;
};

#endif // HEX_H
