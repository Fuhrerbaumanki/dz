#include "Array.h"
#include <cstring>
#include <stdexcept>

// Конструктор инициализации
Array::Array(size_t n, unsigned char initial_value) : size(n) {
  if (n > MAX_SIZE) {
    throw std::out_of_range(
        "Размер массива превышает максимально допустимый размер.");
  }
  data = new unsigned char[size];
  std::memset(data, initial_value, size);
}

// Деструктор
Array::~Array() { delete[] data; }

// Перегрузка оператора индексирования с проверкой допустимости индекса
unsigned char &Array::operator[](size_t index) {
  if (index >= size) {
    throw std::out_of_range("Индекс выходит за пределы массива.");
  }
  return data[index];
}

const unsigned char &Array::operator[](size_t index) const {
  if (index >= size) {
    throw std::out_of_range("Индекс выходит за пределы массива.");
  }
  return data[index];
}

// Метод для получения размера массива
size_t Array::getSize() const { return size; }

// Виртуальная функция поэлементного сложения массивов
Array *Array::add(const Array &other) const {
  if (size != other.size) {
    throw std::invalid_argument("Размеры массивов не совпадают.");
  }
  Array *result = new Array(size);
  for (size_t i = 0; i < size; ++i) {
    result->data[i] = this->data[i] + other.data[i];
  }
  return result;
}
