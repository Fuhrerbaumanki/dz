#include "Angle.h"
#include <cmath>

// Конструктор
Angle::Angle(int deg, int min) : degrees(deg), minutes(min) {}

// Метод для преобразования угла в радианы
double Angle::toRadians() const {
  double totalDegrees = degrees + (minutes / 60.0);
  return totalDegrees * M_PI / 180.0;
}

// Метод для приведения угла к диапазону 0-360
void Angle::normalize() {
  if (degrees >= 360) {
    degrees %= 360;
  } else if (degrees < 0) {
    degrees = (degrees % 360 + 360) % 360;
  }

  if (minutes >= 60) {
    degrees += minutes / 60;
    minutes %= 60;
  } else if (minutes < 0) {
    int borrow = (-minutes + 59) / 60;
    degrees -= borrow;
    minutes = 60 - (-minutes + 60 * borrow);
  }
}

// Методы для увеличения и уменьшения угла на заданную величину
void Angle::increase(int deg, int min) {
  degrees += deg;
  minutes += min;
  normalize();
}

void Angle::decrease(int deg, int min) {
  degrees -= deg;
  minutes -= min;
  normalize();
}

// Метод для вычисления синуса угла
double Angle::sin() const { return std::sin(toRadians()); }

// Метод для сравнения углов
bool Angle::operator==(const Angle &other) const {
  return degrees == other.degrees && minutes == other.minutes;
}

bool Angle::operator!=(const Angle &other) const { return !(*this == other); }
