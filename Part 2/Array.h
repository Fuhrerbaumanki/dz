#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>

class Array {
protected:
  unsigned char *data; // массив
  size_t size;         // количество элементов

public:
  static const size_t MAX_SIZE = 100; // максимально возможный размер массива

  // Конструктор инициализации
  Array(size_t n = 0, unsigned char initial_value = 0);

  // Деструктор
  virtual ~Array();

  // Перегрузка оператора индексирования с проверкой допустимости индекса
  unsigned char &operator[](size_t index);
  const unsigned char &operator[](size_t index) const;

  // Метод для получения размера массива
  size_t getSize() const;

  // Виртуальная функция поэлементного сложения массивов
  virtual Array *add(const Array &other) const;
};

#endif // ARRAY_H
