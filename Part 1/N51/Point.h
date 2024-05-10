#pragma once
#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point {
private:
  double x;
  double y;
  static int count;

public:
  // Конструктор/деструктор
  Point(double x_coord, double y_coord);
  ~Point();

  // Методы доступа
  double get_x() const;
  double get_y() const;

  // Действия с точкой
  void move_x(double dx);
  void move_y(double dy);
  double distance_to_origin();
  double distance_to_point(const Point &other_point);
  std::pair<double, double> to_polar();

  // Перегруженные операторы
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;

  // Кол-во объектов
  static int getCount();
  static void resetCount();
};

#endif
