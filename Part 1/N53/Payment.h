#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include "Money.h"

class Payment {
private:
  std::string full_name;
  Money salary;
  int employment_year;
  int employment_month;
  int employment_day;
  double bonus_percentage;
  double income_tax;
  unsigned int worked_days;
  unsigned int working_days_per_month;
  Money accrued_amount;
  Money withheld_amount;

public:
  // Конструкторы
  Payment();
  Payment(const std::string &name, const Money &base_salary, int year,
          int month, int day, double bonus_percent, double tax_rate,
          unsigned int worked, unsigned int working_days);

  // Методы доступа к полям
  void setFullName(const std::string &name);
  void setSalary(const Money &base_salary);
  void setEmploymentDate(int year, int month, int day);
  void setBonusPercentage(double bonus_percent);
  void setIncomeTax(double tax_rate);
  void setWorkedDays(unsigned int worked);
  void setWorkingDaysPerMonth(unsigned int working_days);
  void setAccruedAmount(const Money &accrued);
  void setWithheldAmount(const Money &withheld);

  std::string getFullName() const;
  Money getSalary() const;
  int getEmploymentYear() const;
  int getEmploymentMonth() const;
  int getEmploymentDay() const;
  double getBonusPercentage() const;
  double getIncomeTax() const;
  unsigned int getWorkedDays() const;
  unsigned int getWorkingDaysPerMonth() const;
  Money getAccruedAmount() const;
  Money getWithheldAmount() const;

  // Методы для вычислений
  void calculateAccruedAmount();
  void calculateWithheldAmount();
};

#endif // PAYMENT_H
