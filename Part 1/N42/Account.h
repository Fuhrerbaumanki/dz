#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Money {
private:
  int rubles; // Рубли
  int kopeks; // Копейки

public:
  Money(int rubles = 0, int kopeks = 0);

  friend std::ostream &operator<<(std::ostream &os, const Money &money);
  std::string amountInWords() const;
};

class Account {
private:
  std::string ownerLastName; // Фамилия владельца
  std::string accountNumber; // Номер счёта
  float interestRate;        // Процент начисления
  Money balance;             // Сумма на счете

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
  std::string balanceInWords() const;
};

#endif // ACCOUNT_H
