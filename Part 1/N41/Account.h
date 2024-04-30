#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Money.h" // Подключаем заголовочный файл с классом Money
#include <string>

class Account {
private:
  std::string ownerName;
  std::string accountNumber;
  double interestRate;
  Money balance;

public:
  // Конструктор с параметрами
  Account(const std::string &name, const std::string &number, double rate,
          const Money &initialBalance);

  // Метод для изменения владельца счета
  void changeOwner(const std::string &newName);

  // Метод для снятия суммы со счета
  void withdraw(const Money &amount);

  // Метод для зачисления суммы на счет
  void deposit(const Money &amount);

  // Метод для начисления процентов
  void addInterest();

  // Метод для перевода суммы в доллары
  double Money convertToDollars() const;

  // Метод для перевода суммы в евро
  double convertToEuros(double exchangeRate) const;

  // Метод для получения суммы прописью
  void spellOut() const;
};

#endif // ACCOUNT_H
