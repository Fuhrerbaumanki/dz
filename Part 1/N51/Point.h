#pragma once
#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
private:
  double x;
  double y;

public:
  Point(double x_coord, double y_coord);

  double get_x() const;
  double get_y() const;

  void move_x(double dx);
  void move_y(double dy);
  double distance_to_origin();
  double distance_to_point(const Point &other_point);
  std::pair<double, double> to_polar();
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;
};

#endif
