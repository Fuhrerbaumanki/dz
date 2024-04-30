#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Angle.h"

class Triangle {
private:
  double side1;
  double side2;
  double side3;
  Angle angle1;
  Angle angle2;
  Angle angle3;

public:
  // Конструктор
  Triangle(double s1, double s2, double s3, const Angle &a1, const Angle &a2,
           const Angle &a3);

  // Методы доступа к полям
  double getSide1() const;
  double getSide2() const;
  double getSide3() const;
  Angle getAngle1() const;
  Angle getAngle2() const;
  Angle getAngle3() const;

  void setSide1(double s);
  void setSide2(double s);
  void setSide3(double s);
  void setAngle1(const Angle &a);
  void setAngle2(const Angle &a);
  void setAngle3(const Angle &a);

  // Методы для вычисления площади, периметра и высот треугольника
  double area() const;
  double perimeter() const;
  double height1() const;
  double height2() const;
  double height3() const;

  // Метод для определения вида треугольника
  enum TriangleType { EQUILATERAL, ISOSCELES, SCALENE, RIGHT };
  TriangleType type() const;
};

#endif // TRIANGLE_H
