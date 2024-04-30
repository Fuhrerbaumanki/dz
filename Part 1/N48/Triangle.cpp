#include "Triangle.h"
#include <cmath>

// Конструктор
Triangle::Triangle(double s1, double s2, double s3, const Angle &a1,
                   const Angle &a2, const Angle &a3)
    : side1(s1), side2(s2), side3(s3), angle1(a1), angle2(a2), angle3(a3) {}

// Методы доступа к полям
double Triangle::getSide1() const { return side1; }
double Triangle::getSide2() const { return side2; }
double Triangle::getSide3() const { return side3; }
Angle Triangle::getAngle1() const { return angle1; }
Angle Triangle::getAngle2() const { return angle2; }
Angle Triangle::getAngle3() const { return angle3; }

void Triangle::setSide1(double s) { side1 = s; }
void Triangle::setSide2(double s) { side2 = s; }
void Triangle::setSide3(double s) { side3 = s; }
void Triangle::setAngle1(const Angle &a) { angle1 = a; }
void Triangle::setAngle2(const Angle &a) { angle2 = a; }
void Triangle::setAngle3(const Angle &a) { angle3 = a; }

// Методы для вычисления площади, периметра и высот треугольника
double Triangle::area() const {
  double s = perimeter() / 2;
  return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::perimeter() const { return side1 + side2 + side3; }

double Triangle::height1() const { return 2 * area() / side1; }

double Triangle::height2() const { return 2 * area() / side2; }

double Triangle::height3() const { return 2 * area() / side3; }

// Метод для определения вида треугольника
Triangle::TriangleType Triangle::type() const {
  if (side1 == side2 && side2 == side3)
    return EQUILATERAL;
  else if (side1 == side2 || side1 == side3 || side2 == side3)
    return ISOSCELES;
  else if (pow(side1, 2) + pow(side2, 2) == pow(side3, 2) ||
           pow(side1, 2) + pow(side3, 2) == pow(side2, 2) ||
           pow(side2, 2) + pow(side3, 2) == pow(side1, 2))
    return RIGHT;
  else
    return SCALENE;
}
