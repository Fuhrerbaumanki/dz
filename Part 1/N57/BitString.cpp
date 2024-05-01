#include "BitString.h"

BitString::BitString(unsigned long value) {
  high = 0;
  low = value & 0xFFFFFFFFFFFFFFFF;
}

BitString::~BitString() {}

BitString BitString::operator&(const BitString &other) const {
  BitString result;
  result.high = high & other.high;
  result.low = low & other.low;
  return result;
}

BitString BitString::operator|(const BitString &other) const {
  BitString result;
  result.high = high | other.high;
  result.low = low | other.low;
  return result;
}

BitString BitString::operator^(const BitString &other) const {
  BitString result;
  result.high = high ^ other.high;
  result.low = low ^ other.low;
  return result;
}

BitString BitString::operator~() const {
  BitString result;
  result.high = ~high;
  result.low = ~low;
  return result;
}

BitString BitString::operator<<(int n) const {
  BitString result;
  if (n >= 64) {
    result.high = low << (n - 64);
    result.low = 0;
  } else {
    result.high = (high << n) | (low >> (64 - n));
    result.low = low << n;
  }
  return result;
}

BitString BitString::operator>>(int n) const {
  BitString result;
  if (n >= 64) {
    result.low = high >> (n - 64);
    result.high = 0;
  } else {
    result.low = (low >> n) | (high << (64 - n));
    result.high = high >> n;
  }
  return result;
}

void BitString::shiftLeft(int n) {
  if (n >= 64) {
    high = low << (n - 64);
    low = 0;
  } else {
    high = (high << n) | (low >> (64 - n));
    low = low << n;
  }
}

void BitString::shiftRight(int n) {
  if (n >= 64) {
    low = high >> (n - 64);
    high = 0;
  } else {
    low = (low >> n) | (high << (64 - n));
    high = high >> n;
  }
}

std::ostream &operator<<(std::ostream &os, const BitString &bs) {
  os << std::hex << bs.high << bs.low;
  return os;
}

unsigned long BitString::getLow() const { return low; }

unsigned long BitString::getHigh() const { return high; }
