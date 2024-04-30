#include "Money.h" // Подключаем заголовочный файл с классом Money
#include <iostream>
#include <string>

class Account {
private:
  std::string ownerName;
  std::string accountNumber;
  double interestRate;
  Money balance; // Используем класс Money для хранения суммы на счете

public:
  // Конструктор с параметрами
  Account(const std::string &name, const std::string &number, double rate,
          const Money &initialBalance)
      : ownerName(name), accountNumber(number), interestRate(rate),
        balance(initialBalance) {}

  // Метод для изменения владельца счета
  void changeOwner(const std::string &newName) { ownerName = newName; }

  // Метод для снятия суммы со счета
  void withdraw(const Money &amount) {
    // Проверяем, достаточно ли средств на счете
    if (balance >= amount) {
      balance = balance - amount;
      std::cout << "Сумма успешно снята со счета." << std::endl;
    } else {
      std::cout << "Ошибка: Недостаточно средств на счете." << std::endl;
    }
  }

  // Метод для зачисления суммы на счет
  void deposit(const Money &amount) {
    // Зачисляем средства на счет
    balance = balance + amount;
    std::cout << "Сумма успешно зачислена на счет." << std::endl;
  }

  // Метод для начисления процентов
  void addInterest() {
    // Начисляем проценты на текущий баланс
    Money interest = balance * (interestRate / 100.0);
    balance = balance + interest;
    std::cout << "Проценты успешно начислены." << std::endl;
  }

  // Метод для перевода суммы в доллары
  double Money::convertToDollars() const {
    // Задаем курс обмена (1 доллар = 92 рубля)
    const double exchangeRate = 92.0;

    // Вычисляем сумму в долларах
    double totalDollars = rubles + kopecks / 100.0;
    totalDollars /= exchangeRate;

    return totalDollars;
  }

  // Метод для перевода суммы в евро
  double convertToEuros(double exchangeRate) const {
    // Переводим текущий баланс в евро
    return balance.convertToEuros(exchangeRate);
  }

  // Метод для получения суммы прописью
  void spellOut() const {
    // Получаем сумму прописью из баланса
    balance.spellOut();
  }
};
