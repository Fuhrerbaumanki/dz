#include "LongLong.h"
#include <iostream>
#include <limits>

LongLong::LongLong(long h, unsigned long l) : high(h), low(l) {}

LongLong LongLong::operator+(const LongLong &other) const {
  unsigned long sum_low = low + other.low;
  long sum_high = high + other.high + (sum_low < low);
  return LongLong(sum_high, sum_low);
}

LongLong LongLong::operator-(const LongLong &other) const {
  long diff_high = high - other.high;
  unsigned long diff_low = low;
  if (low < other.low) {
    diff_high--;
    diff_low = std::numeric_limits<unsigned long>::max() - other.low + low + 1;
  } else {
    diff_low -= other.low;
  }
  return LongLong(diff_high, diff_low);
}

LongLong LongLong::operator*(const LongLong &other) const {
  unsigned long a = low >> 16, b = other.low >> 16;
  unsigned long c = low & 0xFFFF, d = other.low & 0xFFFF;
  unsigned long ac = a * c, bd = b * d, abcd = ac + (bd << 16);
  unsigned long prod_low = abcd & 0xFFFFFFFF;
  unsigned long carry = abcd >> 32;
  unsigned long ad_cb = (a * d) + (b * c);
  unsigned long prod_high = high * other.low + other.high * low + ad_cb + carry;
  return LongLong(prod_high, prod_low);
}

LongLong &LongLong::operator<<=(int shift) {
  if (shift >= 64) {
    high = low << (shift - 64);
    low = 0;
  } else {
    high = (high << shift) | (low >> (64 - shift));
    low <<= shift;
  }
  return *this;
}

LongLong &LongLong::operator-=(const LongLong &other) {
  if (low < other.low) {
    high -= 1;
  }
  low -= other.low;

  if (high < other.high) {
    high = 0;
    low = 0;
  } else {
    high -= other.high;
  }

  return *this;
}

LongLong LongLong::operator/(const LongLong &other) const {
  LongLong dividend = *this;
  LongLong divisor = other;
  LongLong quotient(0, 0);
  LongLong remainder(0, 0);

  for (int i = 63; i >= 0; i--) {
    remainder <<= 1;
    if (dividend.high & (1L << i)) {
      remainder.low |= 1;
    }
    if (remainder >= divisor) {
      remainder -= divisor;
      quotient.low |= (1UL << i);
    }
  }

  return quotient;
}

LongLong LongLong::operator%(const LongLong &other) const {
  LongLong dividend = *this;
  LongLong divisor = other;
  LongLong remainder(0, 0);

  for (int i = 63; i >= 0; i--) {
    remainder <<= 1;
    if (dividend.high & (1L << i)) {
      remainder.low |= 1;
    }
    if (remainder >= divisor) {
      remainder -= divisor;
    }
  }

  return remainder;
}

bool LongLong::operator==(const LongLong &other) const {
  return high == other.high && low == other.low;
}

bool LongLong::operator!=(const LongLong &other) const {
  return !(*this == other);
}

bool LongLong::operator<(const LongLong &other) const {
  if (high < other.high)
    return true;
  else if (high > other.high)
    return false;
  else
    return low < other.low;
}

bool LongLong::operator>(const LongLong &other) const { return other < *this; }

bool LongLong::operator<=(const LongLong &other) const {
  return !(*this > other);
}

bool LongLong::operator>=(const LongLong &other) const {
  return !(*this < other);
}

std::ostream &operator<<(std::ostream &os, const LongLong &ll);

std::ostream &operator<<(std::ostream &os, const LongLong &ll) {
  os << ll.high << ":" << ll.low;
  return os;
}
