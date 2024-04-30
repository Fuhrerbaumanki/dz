#include "Payment.h"

Payment::Payment()
    : salary(0), bonus_percentage(0), income_tax(0), worked_days(0),
      working_days_per_month(0), accrued_amount(0), withheld_amount(0) {}

Payment::Payment(const std::string &name, double base_salary,
                 const Date &employment, double bonus_percent, double tax_rate,
                 unsigned int worked, unsigned int working_days)
    : full_name(name), salary(base_salary), employment_date(employment),
      bonus_percentage(bonus_percent), income_tax(tax_rate),
      worked_days(worked), working_days_per_month(working_days),
      accrued_amount(0), withheld_amount(0) {}

void Payment::setFullName(const std::string &name) { full_name = name; }

void Payment::setSalary(double base_salary) { salary = base_salary; }

void Payment::setEmploymentDate(const Date &employment) {
  employment_date = employment;
}

void Payment::setBonusPercentage(double bonus_percent) {
  bonus_percentage = bonus_percent;
}

void Payment::setIncomeTax(double tax_rate) { income_tax = tax_rate; }

void Payment::setWorkedDays(unsigned int worked) { worked_days = worked; }

void Payment::setWorkingDaysPerMonth(unsigned int working_days) {
  working_days_per_month = working_days;
}

void Payment::setAccruedAmount(double accrued) { accrued_amount = accrued; }

void Payment::setWithheldAmount(double withheld) { withheld_amount = withheld; }

std::string Payment::getFullName() const { return full_name; }

double Payment::getSalary() const { return salary; }

Date Payment::getEmploymentDate() const { return employment_date; }

double Payment::getBonusPercentage() const { return bonus_percentage; }

double Payment::getIncomeTax() const { return income_tax; }

unsigned int Payment::getWorkedDays() const { return worked_days; }

unsigned int Payment::getWorkingDaysPerMonth() const {
  return working_days_per_month;
}

double Payment::getAccruedAmount() const { return accrued_amount; }

double Payment::getWithheldAmount() const { return withheld_amount; }

double Payment::calculateAccruedAmount() const {
  // Начисления = (оклад * отработанные дни / рабочие дни) + (оклад * процент
  // надбавки)
  double base_payment = salary * static_cast<double>(worked_days) /
                        static_cast<double>(working_days_per_month);
  double bonus_payment = salary * bonus_percentage;
  return base_payment + bonus_payment;
}

double Payment::calculateWithheldAmount() const {
  // Удержания = начисления * (подоходный налог + процент в пенсионный фонд)
  double accrued = calculateAccruedAmount();
  double pension_contribution =
      0.01 * accrued; // 1% от начисленной суммы в пенсионный фонд
  double income_tax_amount = 0.13 * accrued; // 13% подоходного налога
  return pension_contribution + income_tax_amount;
}

double Payment::calculateNetSalary() const {
  // Начисленная сумма - удержанная сумма
  return calculateAccruedAmount() - calculateWithheldAmount();
}

unsigned int Payment::calculateExperience() const {
  // Текущий год - год поступления на работу
  unsigned int current_year = Date().getYear();
  unsigned int employment_year = employment_date.getYear();
  return current_year - employment_year;
}
