#include "Account.h"
#include <iostream>

// Конструктор с параметрами
Account::Account(const std::string &lastName, const std::string &accNumber,
                 double interest, const Money &initialBalance)
    : ownerLastName(lastName), accountNumber(accNumber), interestRate(interest),
      balance(initialBalance) {}

// Смена владельца
void Account::changeOwner(const std::string &newOwner) {
  ownerLastName = newOwner;
}

// Снять сумму со счёта
void Account::withdraw(const Money &amount) {
  if (balance < amount) {
    std::cout << "Insufficient funds\n";
  } else {
    balance = balance - amount;
  }
}

// Положить деньги на счёт
void Account::deposit(const Money &amount) { balance = balance + amount; }

// Начислить проценты
void Account::addInterest() {
  Money interestAmount = balance * (interestRate / 100);
  balance = balance + interestAmount;
}

// Перевести сумму в доллары
Money Account::convertToUSD(double usdRate) const {
  double amountInUSD =
      (balance.getRubles() + balance.getKopecks() / 100.0) / usdRate;
  long rublesInUSD = static_cast<long>(amountInUSD);
  unsigned char kopecksInUSD =
      static_cast<unsigned char>((amountInUSD - rublesInUSD) * 100);
  return Money(rublesInUSD, kopecksInUSD);
}

// Перевести сумму в евро
Money Account::convertToEUR(double eurRate) const {
  double amountInEUR =
      (balance.getRubles() + balance.getKopecks() / 100.0) / eurRate;
  long rublesInEUR = static_cast<long>(amountInEUR);
  unsigned char kopecksInEUR =
      static_cast<unsigned char>((amountInEUR - rublesInEUR) * 100);
  return Money(rublesInEUR, kopecksInEUR);
}
