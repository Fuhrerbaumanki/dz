#include "Payment.h"

Payment::Payment()
    : bonus_percentage(0), income_tax(0), worked_days(0),
      working_days_per_month(0) {}

Payment::Payment(const std::string &name, const Money &base_salary, int year,
                 int month, int day, double bonus_percent, double tax_rate,
                 unsigned int worked, unsigned int working_days)
    : full_name(name), salary(base_salary), employment_year(year),
      employment_month(month), employment_day(day),
      bonus_percentage(bonus_percent), income_tax(tax_rate),
      worked_days(worked), working_days_per_month(working_days) {}

void Payment::setFullName(const std::string &name) { full_name = name; }

void Payment::setSalary(const Money &base_salary) { salary = base_salary; }

void Payment::setEmploymentDate(int year, int month, int day) {
  employment_year = year;
  employment_month = month;
  employment_day = day;
}

void Payment::setBonusPercentage(double bonus_percent) {
  bonus_percentage = bonus_percent;
}

void Payment::setIncomeTax(double tax_rate) { income_tax = tax_rate; }

void Payment::setWorkedDays(unsigned int worked) { worked_days = worked; }

void Payment::setWorkingDaysPerMonth(unsigned int working_days) {
  working_days_per_month = working_days;
}

void Payment::setAccruedAmount(const Money &accrued) {
  accrued_amount = accrued;
}

void Payment::setWithheldAmount(const Money &withheld) {
  withheld_amount = withheld;
}

std::string Payment::getFullName() const { return full_name; }

Money Payment::getSalary() const { return salary; }

int Payment::getEmploymentYear() const { return employment_year; }

int Payment::getEmploymentMonth() const { return employment_month; }

int Payment::getEmploymentDay() const { return employment_day; }

double Payment::getBonusPercentage() const { return bonus_percentage; }

double Payment::getIncomeTax() const { return income_tax; }

unsigned int Payment::getWorkedDays() const { return worked_days; }

unsigned int Payment::getWorkingDaysPerMonth() const {
  return working_days_per_month;
}

Money Payment::getAccruedAmount() const { return accrued_amount; }

Money Payment::getWithheldAmount() const { return withheld_amount; }

void Payment::calculateAccruedAmount() {
  // Начисленная сумма = (оклад * отработанные дни / рабочие дни) + (оклад *
  // процент надбавки)
  double base_payment = salary.getRubles() * static_cast<double>(worked_days) /
                        static_cast<double>(working_days_per_month);
  double bonus_payment = salary.getRubles() * bonus_percentage;
  accrued_amount = Money(base_payment + bonus_payment);
}

void Payment::calculateWithheldAmount() {
  // Вычисляем начисленную сумму для последующего расчета удержаний
  calculateAccruedAmount();

  // Удержанная сумма = начисленная сумма * (подоходный налог + процент в
  // пенсионный фонд)
  double accrued_rubles = accrued_amount.getRubles();
  double accrued_kopecks = accrued_amount.getKopecks();
  double accrued_total = accrued_rubles + (accrued_kopecks / 100.0);

  double pension_contribution =
      0.01 * accrued_total; // 1% от начисленной суммы в пенсионный фонд
  double income_tax_amount = 0.01 * accrued_total; // 13% подоходного налога

  // Округляем удержанные суммы до копеек
  long withheld_rubles =
      static_cast<long>(pension_contribution + income_tax_amount);
  unsigned char withheld_kopecks = static_cast<unsigned char>(
      ((pension_contribution + income_tax_amount) - withheld_rubles) * 100);

  withheld_amount = Money(withheld_rubles, withheld_kopecks);
}
