#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Date.h"
#include <string>

class Account {
private:
  std::string ownerName;      // Фамилия владельца
  unsigned int accountNumber; // Номер счета
  double interestRate;        // Процент начисления
  unsigned int amountRubles;  // Сумма в рублях
  Date openingDate;           // Дата открытия счета

public:
  // Конструктор с параметрами для открытия нового счета
  Account(const std::string &owner, unsigned int number, double rate,
          unsigned int initialAmount, const Date &date);

  // Методы доступа к полям
  const std::string &getOwnerName() const;
  unsigned int getAccountNumber() const;
  double getInterestRate() const;
  unsigned int getAmountRubles() const;
  const Date &getOpeningDate() const;

  // Метод для смены владельца счета
  void changeOwner(const std::string &newOwner);

  // Методы для операций со счетом
  void withdraw(unsigned int amount);
  void deposit(unsigned int amount);
  void applyInterest();

  // Методы для конвертации в другие валюты
  double amountInDollars() const;
  double amountInEuro() const;

  // Метод для получения суммы прописью
  std::string amountInWords() const;
};

#endif // ACCOUNT_H
