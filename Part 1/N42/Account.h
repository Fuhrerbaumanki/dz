#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Money.h"
#include <iostream>
#include <string>

class Account {
private:
  std::string ownerLastName; // Фамилия владельца
  std::string accountNumber; // Номер счёта
  float interestRate;        // Процент начисления
  Money balance;             // Сумма на счете
  std::string amountInWords() const;

public:
  Account(const std::string &ownerLastName, const std::string &accountNumber,
          float interestRate, const Money &initialBalance);

  void changeOwner(const std::string &newOwnerLastName);
  void withdraw(const Money &amount);
  void deposit(const Money &amount);
  void addInterest();
  Money toDollars(float exchangeRate) const;
  Money toEuro(float exchangeRate) const;
  Money getBalance() const;
};

#endif // ACCOUNT_H
