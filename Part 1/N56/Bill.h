#pragma once
#ifndef BILL_H
#define BILL_H

#include "Time.h"
#include <iostream>
#include <string>

class Bill {
private:
  std::string lastName;
  std::string phoneNumber;
  double minuteRate;
  double discount;
  Time startTime;
  Time endTime;
  double totalAmount;

public:
  // Конструктор
  Bill(const std::string &last_name, const std::string &phone_number,
       double minute_rate, double disc, const Time &start_time,
       const Time &end_time);

  // Методы для извлечения полей
  std::string getLastName() const;
  std::string getPhoneNumber() const;
  double getMinuteRate() const;
  double getDiscount() const;
  Time getStartTime() const;
  Time getEndTime() const;
  double getTotalAmount() const;

  // Методы для изменения полей
  void setLastName(const std::string &last_name);
  void setPhoneNumber(const std::string &phone_number);
  void setMinuteRate(double minute_rate);
  void setDiscount(double disc);
  void setStartTime(const Time &start_time);
  void setEndTime(const Time &end_time);
  void setTotalAmount(double amount);

  // Метод для вычисления времени разговора в минутах
  int calculateCallDuration() const;
};

#endif // BILL_H
