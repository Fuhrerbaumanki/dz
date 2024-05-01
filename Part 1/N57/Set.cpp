#include "Set.h"
#include "BitString.h"
#include <iostream>

Set::Set() : bits(0) {}

void Set::add(int num) { bits.shiftLeft(num); }

void Set::remove(int num) {
  BitString temp(1);
  temp.shiftLeft(num);
  bits = bits & (~temp);
}

Set Set::unionWith(const Set &other) const {
  Set result;
  result.bits = bits | other.bits;
  return result;
}

Set Set::intersectionWith(const Set &other) const {
  Set result;
  result.bits = bits & other.bits;
  return result;
}

Set Set::differenceWith(const Set &other) const {
  Set result;
  result.bits = bits & (~other.bits);
  return result;
}

int Set::count() const {
  int count = 0;
  BitString temp = bits;
  while (temp.getLow() != 0 || temp.getHigh() != 0) {
    if (temp.getLow() & 1)
      count++;
    temp = temp >> 1;
  }
  return count;
}

void Set::display() const {
  std::cout << "{";
  for (int i = 0; i < 64; ++i) {
    BitString temp(1);
    temp.shiftLeft(i);
    if ((bits & temp).getLow() > 0)
      std::cout << i << " ";
  }
  std::cout << "}" << std::endl;
}
