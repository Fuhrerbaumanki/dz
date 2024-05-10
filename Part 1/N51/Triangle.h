#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
  Point point1;
  Point point2;
  Point point3;
  double side1;
  double side2;
  double side3;
  static int count;

public:
  // Конструктор/деструктор
  Triangle(const Point &p1, const Point &p2, const Point &p3);
  ~Triangle();

  // Геометрические методы
  double get_side1() const;
  double get_side2() const;
  double get_side3() const;
  double perimeter() const;
  double area() const;
  bool is_equilateral() const;
  bool is_isosceles() const;
  bool is_right() const;

  // статические методы для работы с счетчиком
  static int getCount();
  static void resetCount();
};

#endif
