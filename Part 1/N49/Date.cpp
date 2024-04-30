#include "Date.h"
#include <iostream>
#include <string>

// Конструктор по умолчанию
Date::Date() : year(0), month(0), day(0) {}

// Конструктор с числами
Date::Date(unsigned int y, unsigned int m, unsigned int d)
    : year(y), month(m), day(d) {}

// Конструктор со строкой
Date::Date(const std::string &dateStr) {
  size_t dotPos1 = dateStr.find('.');
  size_t dotPos2 = dateStr.find('.', dotPos1 + 1);
  if (dotPos1 != std::string::npos && dotPos2 != std::string::npos) {
    year = std::stoi(dateStr.substr(0, dotPos1));
    month = std::stoi(dateStr.substr(dotPos1 + 1, dotPos2 - dotPos1 - 1));
    day = std::stoi(dateStr.substr(dotPos2 + 1));
  } else {
    std::cerr << "Invalid date format\n";
    year = 0;
    month = 0;
    day = 0;
  }
}

// Конструктор с объектом Date
Date::Date(const Date &other)
    : year(other.year), month(other.month), day(other.day) {}

// Функция для установки новой даты числами
void Date::setDate(unsigned int y, unsigned int m, unsigned int d) {
  year = y;
  month = m;
  day = d;
}

// Функция для установки новой даты строкой
void Date::setDate(const std::string &dateStr) { *this = Date(dateStr); }

// Функция для вывода даты
void Date::printDate() const {
  std::cout << year << "." << month << "." << day << std::endl;
}

// Функция для вычисления даты через заданное количество дней
Date Date::addDays(unsigned int numDays) const {
  Date result(*this); // Создаем копию текущей даты

  // Сначала увеличим день на numDays
  result.day += numDays;

  // Пока день выходит за границы месяца
  while (result.day > daysInMonth(result.year, result.month)) {
    // Вычитаем из текущего дня количество дней в текущем месяце
    result.day -= daysInMonth(result.year, result.month);
    // Увеличиваем месяц на 1
    result.month++;

    // Если месяц выходит за допустимые пределы (больше 12), то переходим на
    // следующий год
    if (result.month > 12) {
      result.month = 1;
      result.year++;
    }
  }

  return result;
}

// Функция для определения количества дней в указанном месяце и году
unsigned int Date::daysInMonth(unsigned int year, unsigned int month) const {
  static const unsigned int days[12] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
  if (month == 2 && isLeapYear()) // Проверяем, является ли февраль високосным
    return 29;
  else
    return days[month - 1];
}

// Функция для вычитания количества дней из текущей даты
Date Date::subtractDays(unsigned int numDays) const {
  Date result(*this);

  // Вычитаем numDays дней из даты
  while (numDays > 0) {
    if (result.day > numDays) {
      result.day -= numDays;
      numDays = 0; // Все дни вычтены
    } else {
      // Уменьшаем месяц
      if (result.month == 1) { // Если текущий месяц январь, переходим к декабрю предыдущего года
        result.month = 12;
        result.year--;
      } else {
        result.month--;
      }
      // Определяем количество дней в предыдущем месяце
      unsigned int daysInPrevMonth = daysInMonth(result.year, result.month);
      // Корректируем количество дней
      result.day = daysInPrevMonth - (numDays - result.day) + 1;
      // Оставшиеся дни для вычитания
      numDays -= result.day;
    }
  }

  return result;
}


// Функция для определения високосности года
bool Date::isLeapYear() const {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функции для получения года, месяца и дня
unsigned int Date::getYear() const { return year; }
unsigned int Date::getMonth() const { return month; }
unsigned int Date::getDay() const { return day; }

// Функция для сравнения дат (равно, до, после)
int Date::compare(const Date &other) const {
  if (year == other.year && month == other.month && day == other.day)
    return 0;
  else if (year > other.year || (year == other.year && month > other.month) ||
           (year == other.year && month == other.month && day > other.day))
    return 1;
  else
    return -1;
}

// Функция для вычисления количества дней между датами
int Date::daysBetween(const Date &other) const {
  // Переводим обе даты в количество дней с начала отсчета (например, с 1
  // января 0001 года)
  long int days1 = julianDay();
  long int days2 = other.julianDay();

  // Возвращаем разницу между днями
  return std::abs(days2 - days1);
}

// Метод для вычисления Юлианского дня (количество дней с начала
// отсчета)
long int Date::julianDay() const {
  // Переводим текущую дату в количество дней с начала отсчета (например, с 1
  // января 0001 года)
  long int a = (14 - month) / 12;
  long int y = year + 4800 - a;
  long int m = month + 12 * a - 3;

  return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

