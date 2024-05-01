#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Money.h"
#include <string>

class Account {
private:
  std::string ownerLastName;
  std::string accountNumber;
  double interestRate; // Процент начисления
  Money balance;       // Сумма на счете

public:
  // Конструктор с параметрами
  Account(const std::string &lastName, const std::string &accNumber,
          double interest, const Money &initialBalance);

  // Методы
  void changeOwner(const std::string &newOwner); // Смена владельца
  void withdraw(const Money &amount); // Снять сумму со счёта
  void deposit(const Money &amount); // Положить деньги на счёт
  void addInterest();                // Начислить проценты

  // Перевести сумму в доллары/евро
  Money convertToUSD(double usdRate) const;
  Money convertToEUR(double eurRate) const;
};

#endif // ACCOUNT_H
