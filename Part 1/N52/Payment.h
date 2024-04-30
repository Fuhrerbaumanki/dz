#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include "Date.h"

class Payment {
private:
  std::string full_name;
  double salary;
  Date employment_date;
  double bonus_percentage;
  double income_tax;
  unsigned int worked_days;
  unsigned int working_days_per_month;
  double accrued_amount;
  double withheld_amount;

public:
  // Конструкторы
  Payment();
  Payment(const std::string &name, double base_salary, const Date &employment,
          double bonus_percent, double tax_rate, unsigned int worked,
          unsigned int working_days);

  // Методы доступа к полям
  void setFullName(const std::string &name);
  void setSalary(double base_salary);
  void setEmploymentDate(const Date &employment);
  void setBonusPercentage(double bonus_percent);
  void setIncomeTax(double tax_rate);
  void setWorkedDays(unsigned int worked);
  void setWorkingDaysPerMonth(unsigned int working_days);
  void setAccruedAmount(double accrued);
  void setWithheldAmount(double withheld);

  std::string getFullName() const;
  double getSalary() const;
  Date getEmploymentDate() const;
  double getBonusPercentage() const;
  double getIncomeTax() const;
  unsigned int getWorkedDays() const;
  unsigned int getWorkingDaysPerMonth() const;
  double getAccruedAmount() const;
  double getWithheldAmount() const;

  // Методы для вычислений

  double calculateAccruedAmount() const;
  double calculateWithheldAmount() const;
  double calculateNetSalary() const;
  unsigned int calculateExperience() const;
};

#endif // PAYMENT_H
