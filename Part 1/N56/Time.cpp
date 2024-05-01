#include "Time.h"
#include <cmath>
#include <iostream>
#include <string>

// Конструкторы
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

Time::Time(const std::string &time_str) {
  sscanf(time_str.c_str(), "%d:%d:%d", &hour, &minute, &second);
}

// Methods
int Time::total_seconds() const { return hour * 3600 + minute * 60 + second; }

int Time::difference(const Time &other) const {
  return abs(total_seconds() - other.total_seconds());
}

Time Time::operator+(int seconds) const {
  int total_secs = total_seconds() + seconds;
  return Time(total_secs / 3600, (total_secs % 3600) / 60, total_secs % 60);
}

Time Time::operator-(int seconds) const {
  int total_secs = total_seconds() - seconds;
  return Time(total_secs / 3600, (total_secs % 3600) / 60, total_secs % 60);
}

bool Time::operator==(const Time &other) const {
  return total_seconds() == other.total_seconds();
}

bool Time::operator<(const Time &other) const {
  return total_seconds() < other.total_seconds();
}

bool Time::operator<=(const Time &other) const {
  return total_seconds() <= other.total_seconds();
}

bool Time::operator>(const Time &other) const {
  return total_seconds() > other.total_seconds();
}

bool Time::operator>=(const Time &other) const {
  return total_seconds() >= other.total_seconds();
}

int Time::to_minutes() const { return round(total_seconds() / 60.0); }

// Метод вывода
std::ostream &operator<<(std::ostream &os, const Time &time) {
  os << time.hour << ":" << time.minute << ":" << time.second;
  return os;
}
