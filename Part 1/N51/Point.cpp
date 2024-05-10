#include "Point.h"
#include <cmath>

// Статическая переменная для подсчёта кол-ва объектов
int Point::count = 0;

// Методы доступа
double Point::get_x() const { return x; }

double Point::get_y() const { return y; }

// Конструктор
Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {
  count++;
}

// Деструктор
Point::~Point() { count--; }

// Двигаем точку по иксу
void Point::move_x(double dx) { x += dx; }

// Двигаем по игрику
void Point::move_y(double dy) { y += dy; }

// Расстояние до центра координат
double Point::distance_to_origin() { return sqrt(x * x + y * y); }

// Расстояние между 2 точками
double Point::distance_to_point(const Point &other_point) {
  double dx = x - other_point.x;
  double dy = y - other_point.y;
  return sqrt(dx * dx + dy * dy);
}

// Перевод в полярку
std::pair<double, double> Point::to_polar() {
  double r = sqrt(x * x + y * y);
  double theta = atan2(y, x);
  return std::make_pair(r, theta);
}

// Перегрузка ==
bool Point::operator==(const Point &other) const {
  return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const { return !(*this == other); }

// Вернуть кол-во объектов
int Point::getCount() { return count; }

// Обнулить кол-во точек
void Point::resetCount() { count = 0; }
