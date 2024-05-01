#include "LongLong.h"

LongLong::LongLong(long high, unsigned long low)
    : highPart(high), lowPart(low) {}

LongLong LongLong::operator+(const LongLong &other) const {
  unsigned long long sum =
      static_cast<unsigned long long>(highPart) * (1ULL << 32) + lowPart;
  sum += static_cast<unsigned long long>(other.highPart) * (1ULL << 32) +
         other.lowPart;

  return LongLong(static_cast<long>(sum >> 32),
                  static_cast<unsigned long>(sum & 0xFFFFFFFF));
}

LongLong LongLong::operator-(const LongLong &other) const {
  unsigned long long diff =
      static_cast<unsigned long long>(highPart) * (1ULL << 32) + lowPart;
  diff -= static_cast<unsigned long long>(other.highPart) * (1ULL << 32) +
          other.lowPart;

  return LongLong(static_cast<long>(diff >> 32),
                  static_cast<unsigned long>(diff & 0xFFFFFFFF));
}

LongLong LongLong::operator*(const LongLong &other) const {
  unsigned long long product =
      static_cast<unsigned long long>(highPart) * (1ULL << 32) + lowPart;
  product *= static_cast<unsigned long long>(other.highPart) * (1ULL << 32) +
             other.lowPart;

  return LongLong(static_cast<long>(product >> 32),
                  static_cast<unsigned long>(product & 0xFFFFFFFF));
}

LongLong LongLong::operator/(const LongLong &other) const {
  if (other.highPart == 0 && other.lowPart == 0) {
    // Division by zero
    return LongLong(0, 0);
  }

  unsigned long long dividend =
      static_cast<unsigned long long>(highPart) * (1ULL << 32) + lowPart;
  unsigned long long divisor =
      static_cast<unsigned long long>(other.highPart) * (1ULL << 32) +
      other.lowPart;

  return LongLong(static_cast<long>(dividend / divisor),
                  static_cast<unsigned long>(dividend % divisor));
}

LongLong LongLong::operator%(const LongLong &other) const {
  if (other.highPart == 0 && other.lowPart == 0) {
    // Division by zero
    return LongLong(0, 0);
  }

  unsigned long long dividend =
      static_cast<unsigned long long>(highPart) * (1ULL << 32) + lowPart;
  unsigned long long divisor =
      static_cast<unsigned long long>(other.highPart) * (1ULL << 32) +
      other.lowPart;

  return LongLong(0, static_cast<unsigned long>(dividend % divisor));
}

bool LongLong::operator==(const LongLong &other) const {
  return highPart == other.highPart && lowPart == other.lowPart;
}

bool LongLong::operator!=(const LongLong &other) const {
  return !(*this == other);
}

bool LongLong::operator<(const LongLong &other) const {
  if (highPart < other.highPart)
    return true;
  if (highPart > other.highPart)
    return false;
  return lowPart < other.lowPart;
}

bool LongLong::operator<=(const LongLong &other) const {
  return (*this < other) || (*this == other);
}

bool LongLong::operator>(const LongLong &other) const {
  return !(*this <= other);
}

bool LongLong::operator>=(const LongLong &other) const {
  return !(*this < other);
}

long LongLong::getHighPart() const { return highPart; }

unsigned long LongLong::getLowPart() const { return lowPart; }

LongLong LongLong::operator/(double divisor) const {
  long newHighPart = static_cast<long>(highPart / divisor);
  unsigned long newLowPart = static_cast<unsigned long>(lowPart / divisor);
  return LongLong(newHighPart, newLowPart);
}
