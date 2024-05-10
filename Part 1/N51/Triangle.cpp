#include "Triangle.h"
#include <cmath>

int Triangle::count = 0;

// Конструктор
Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : point1(p1), point2(p2), point3(p3) {
  // Вычисляем длины сторон треугольника
  side1 = point1.distance_to_point(point2);
  side2 = point2.distance_to_point(point3);
  side3 = point3.distance_to_point(point1);
  count++;
}

// Деструктор
Triangle::~Triangle() {
  count--; // Уменьшение счетчика
}

// Геом. методы
double Triangle::get_side1() const { return side1; }

double Triangle::get_side2() const { return side2; }

double Triangle::get_side3() const { return side3; }

double Triangle::perimeter() const { return side1 + side2 + side3; }

double Triangle::area() const {
  // Ф-ла Герона
  double s = perimeter() / 2;
  return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

bool Triangle::is_equilateral() const {
  return side1 == side2 && side2 == side3;
}

bool Triangle::is_isosceles() const {
  return side1 == side2 || side2 == side3 || side3 == side1;
}

bool Triangle::is_right() const {
  // Проверяем, удовлетворяет ли треугольник теореме Пифагора
  double a2 = side1 * side1;
  double b2 = side2 * side2;
  double c2 = side3 * side3;
  return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}

// Работа с счётчиком
int Triangle::getCount() { return count; }

void Triangle::resetCount() { count = 0; }
