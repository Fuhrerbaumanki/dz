#include <cmath>
#include <iostream>
#include <string>

class Time {
private:
  int hour;
  int minute;
  int second;

public:
  // Constructors
  Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
  Time(const std::string &time_str) {
    sscanf(time_str.c_str(), "%d:%d:%d", &hour, &minute, &second);
  }

  // Methods
  int total_seconds() const { return hour * 3600 + minute * 60 + second; }

  int difference(const Time &other) const {
    return abs(total_seconds() - other.total_seconds());
  }

  Time operator+(int seconds) const {
    int total_secs = total_seconds() + seconds;
    return Time(total_secs / 3600, (total_secs % 3600) / 60, total_secs % 60);
  }

  Time operator-(int seconds) const {
    int total_secs = total_seconds() - seconds;
    return Time(total_secs / 3600, (total_secs % 3600) / 60, total_secs % 60);
  }

  bool operator==(const Time &other) const {
    return total_seconds() == other.total_seconds();
  }

  bool operator<(const Time &other) const {
    return total_seconds() < other.total_seconds();
  }

  bool operator<=(const Time &other) const {
    return total_seconds() <= other.total_seconds();
  }

  bool operator>(const Time &other) const {
    return total_seconds() > other.total_seconds();
  }

  bool operator>=(const Time &other) const {
    return total_seconds() >= other.total_seconds();
  }

  int to_minutes() const { return round(total_seconds() / 60.0); }

  // Friend function to output Time object
  friend std::ostream &operator<<(std::ostream &os, const Time &time) {
    os << time.hour << ":" << time.minute << ":" << time.second;
    return os;
  }
};
