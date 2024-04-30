#include "Point.h"
#include <cmath>

double Point::get_x() const { return x; }

double Point::get_y() const { return y; }

Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

void Point::move_x(double dx) { x += dx; }

void Point::move_y(double dy) { y += dy; }

double Point::distance_to_origin() { return sqrt(x * x + y * y); }

double Point::distance_to_point(const Point &other_point) {
  double dx = x - other_point.x;
  double dy = y - other_point.y;
  return sqrt(dx * dx + dy * dy);
}

std::pair<double, double> Point::to_polar() {
  double r = sqrt(x * x + y * y);
  double theta = atan2(y, x);
  return std::make_pair(r, theta);
}

bool Point::operator==(const Point &other) const {
  return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const { return !(*this == other); }
