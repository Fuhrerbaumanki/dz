#include "Octal.h"
#include <cstring>
#include <stdexcept>

Octal::Octal(int size) : Array(size) {}

Octal::Octal(const Octal &other) : Array(other.size) {
  std::memcpy(data, other.data, size);
}

Octal::~Octal() {}

int Octal::setDigit(int index, unsigned char value) {
  if (index >= size) {
    return -1; // Error: Index out of range
  }
  data[index] = value;
  return 0; // Success
}

unsigned char Octal::getDigit(int index) const {
  if (index >= size) {
    throw std::out_of_range("Индекс выходит за пределы массива.");
  }
  return data[index];
}

Octal Octal::operator+(const Octal &other) const {
  Octal result(size);
  for (int i = 0; i < size; ++i) {
    result.data[i] = this->data[i] + other.data[i];
  }
  return result;
}

// Implement other operators similarly
// ...

bool Octal::operator==(const Octal &other) const {
  return std::memcmp(data, other.data, size) == 0;
}

bool Octal::operator!=(const Octal &other) const { return !(*this == other); }

// Implement other comparison operators similarly
// ...

Array *Octal::add(const Array &other) const {
  const Octal &octal = dynamic_cast<const Octal &>(other);
  return new Octal(*this + octal);
}
