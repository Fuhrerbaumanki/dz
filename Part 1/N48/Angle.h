#pragma once
#ifndef ANGLE_H
#define ANGLE_H

class Angle {
private:
  int degrees;
  int minutes;

public:
  // Конструктор
  Angle(int deg, int min);

  // Метод для преобразования угла в радианы
  double toRadians() const;

  // Метод для приведения угла к диапазону 0-360
  void normalize();

  // Методы для увеличения и уменьшения угла на заданную величину
  void increase(int deg, int min);
  void decrease(int deg, int min);

  // Метод для вычисления синуса угла
  double sin() const;

  // Метод для сравнения углов
  bool operator==(const Angle &other) const;
  bool operator!=(const Angle &other) const;
};

#endif // ANGLE_H
