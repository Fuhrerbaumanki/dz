#include "Hex.h"
#include <cstring>
#include <stdexcept>

Hex::Hex(int size) : Array(size) {}

Hex::Hex(const Hex &hex) : Array(hex.size) {
  std::memcpy(data, hex.data, size);
}

Hex::~Hex() {}

int Hex::setDigit(int index, unsigned char value) {
  if (index >= size) {
    return -1; // Error: Index out of range
  }
  data[index] = value;
  return 0; // Success
}

unsigned char Hex::getDigit(int index) const {
  if (index >= size) {
    throw std::out_of_range("Индекс выходит за пределы массива.");
  }
  return data[index];
}

Hex Hex::operator+(const Hex &hex) const {
  Hex result(size);
  for (int i = 0; i < size; ++i) {
    result.data[i] = this->data[i] + hex.data[i];
  }
  return result;
}

bool Hex::operator==(const Hex &hex) const {
  return std::memcmp(data, hex.data, size) == 0;
}

bool Hex::operator!=(const Hex &hex) const { return !(*this == hex); }

Array *Hex::add(const Array &other) const {
  const Hex &hex = dynamic_cast<const Hex &>(other);
  return new Hex(*this + hex);
}
