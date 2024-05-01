#include "Account.h"
#include <string>

// Метод для получения суммы прописью
std::string Account::amountInWords() const {
  std::string units[] = {"рубль", "рубля", "рублей"};
  std::string tens[] = {"десять",    "двадцать",    "тридцать",
                        "сорок",     "пятьдесят",   "шестьдесят",
                        "семьдесят", "восемьдесят", "девяносто"};
  std::string teens[] = {"одиннадцать",  "двенадцать",   "тринадцать",
                         "четырнадцать", "пятнадцать",   "шестнадцать",
                         "семнадцать",   "восемнадцать", "девятнадцать"};
  std::string ones[] = {"",     "один",  "два",  "три",    "четыре",
                        "пять", "шесть", "семь", "восемь", "девять"};

  std::string result;

  int rubles_units = balance.getRubles() % 10;
  int rubles_tens = (balance.getRubles() % 100) / 10;
  if (rubles_tens == 1) {
    result += teens[rubles_units] + " ";
  } else {
    result += tens[rubles_tens - 1] + " ";
    result += ones[rubles_units] + " ";
  }

  if (rubles_units == 0 || (rubles_units > 4 && rubles_units <= 9) ||
      (rubles_tens == 1))
    result += units[2];
  else if (rubles_units == 1)
    result += units[0];
  else
    result += units[1];

  if (balance.getKopecks() > 0) {
    int kopeks_units = balance.getKopecks() % 10;
    int kopeks_tens = (balance.getKopecks() % 100) / 10;
    result +=
        " " + tens[kopeks_tens - 1] + " " + ones[kopeks_units] + " копеек";
  }

  return result;
}

// Конструктор для открытия нового счёта
Account::Account(const std::string &ownerLastName,
                 const std::string &accountNumber, float interestRate,
                 const Money &initialBalance)
    : ownerLastName(ownerLastName), accountNumber(accountNumber),
      interestRate(interestRate), balance(initialBalance) {}

// Метод для смены владельца счёта
void Account::changeOwner(const std::string &newOwnerLastName) {
  ownerLastName = newOwnerLastName;
}

// Метод для снятия суммы
void Account::withdraw(const Money &amount) {
  if (balance < amount) {
    std::cout << "Недостаточно средств на счете" << std::endl;
  } else {
    balance = balance - amount;
    std::cout << "Сумма " << amount << " успешно снята" << std::endl;
  }
}

// Метод для внесения суммы
void Account::deposit(const Money &amount) {
  balance = balance + amount;
  std::cout << "Сумма " << amount << " успешно внесена" << std::endl;
}

// Метод для начисления процентов
void Account::addInterest() {
  Money interest = balance * (interestRate / 100);
  balance = balance + interest;
  std::cout << "Проценты успешно начислены" << std::endl;
}

// Метод для перевода суммы в доллары
Money Account::toDollars(float exchangeRate) const {
  // exchangeRate - это курс обмена рубля на доллар
  Money convertedAmount = balance * exchangeRate;
  return convertedAmount;
}

// Метод для перевода суммы в евро
Money Account::toEuro(float exchangeRate) const {
  Money convertedAmount = balance * exchangeRate;
  return convertedAmount;
}

// Метод для получения суммы на счете
Money Account::getBalance() const { return balance; }
