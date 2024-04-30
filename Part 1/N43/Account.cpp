#include "Account.h"
#include "Date.h"
#include <cmath>
#include <vector>

// Конструктор с параметрами
Account::Account(const std::string &owner, unsigned int number, double rate,
                 unsigned int initialAmount, const Date &date)
    : ownerName(owner), accountNumber(number), interestRate(rate),
      amountRubles(initialAmount), openingDate(date) {}

// Методы доступа к полям
#include "Account.h"

// Метод для получения имени владельца
const std::string &Account::getOwnerName() const { return ownerName; }

// Метод для получения номера счета
unsigned int Account::getAccountNumber() const { return accountNumber; }

// Метод для получения процентной ставки
double Account::getInterestRate() const { return interestRate; }

// Метод для получения суммы в рублях
unsigned int Account::getAmountRubles() const { return amountRubles; }

// Метод для смены владельца счета
void Account::changeOwner(const std::string &newName) { ownerName = newName; }

// Методы для операций со счетом
void Account::withdraw(unsigned int amountRubles) {
  if (amountRubles <= this->amountRubles) {
    this->amountRubles -= amountRubles;
    std::cout << "Вы сняли " << amountRubles << " рублей со счета.\n";
  } else {
    std::cout << "На счете недостаточно средств.\n";
  }
}

// Метод для внесения средств на счет
void Account::deposit(unsigned int amountRubles) {
  this->amountRubles += amountRubles;
  std::cout << "Вы внесли " << amountRubles << " рублей на счет.\n";
}

// Метод для начисления процентов
void Account::applyInterest() {
  unsigned int interest = static_cast<unsigned int>(
      std::round(amountRubles * (interestRate / 100.0)));
  this->amountRubles += interest;
  std::cout << "Проценты в размере " << interest
            << " рублей начислены на счет.\n";
}

// Методы для конвертации в другие валюты
double Account::amountInDollars() const {
  return amountRubles / 93.5; // Предположим, курс 1 USD = 93.5 RUB
}

double Account::amountInEuro() const {
  return amountRubles / 95.2; // Предположим, курс 1 EUR = 95.2 RUB
}

std::string ones[] = {"",     "один",  "два",  "три",    "четыре",
                      "пять", "шесть", "семь", "восемь", "девять"};
std::string tens[] = {
    "",          "",           "двадцать",  "тридцать",    "сорок",
    "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
std::string hundreds[] = {"",          "сто",      "двести",   "триста",
                          "четыреста", "пятьсот",  "шестьсот", "семьсот",
                          "восемьсот", "девятьсот"};

std::string amountInWords(unsigned int amountRubles) {
  if (amountRubles == 0)
    return "ноль рублей";

  std::string result;

  // Разбиваем число на триады
  std::vector<int> triads;
  while (amountRubles > 0) {
    triads.push_back(amountRubles % 1000);
    amountRubles /= 1000;
  }

  // Преобразуем каждую триаду
  std::vector<std::string> triadWords;
  for (int i = triads.size() - 1; i >= 0; --i) {
    int triad = triads[i];
    std::string triadWord;

    int onesDigit = triad % 10;
    int tensDigit = (triad / 10) % 10;
    int hundredsDigit = (triad / 100) % 10;

    if (hundredsDigit > 0)
      triadWord += hundreds[hundredsDigit] + " ";

    if (tensDigit == 1) {
      triadWord += ones[10 + onesDigit];
    } else {
      triadWord += tens[tensDigit];
      triadWord += " " + ones[onesDigit];
    }

    if (triad > 0) {
      if (onesDigit == 1 && tensDigit != 1 && tensDigit != 0)
        triadWord += " рубль";
      else if ((onesDigit >= 2 && onesDigit <= 4) ||
               (onesDigit == 0 && tensDigit != 1 && tensDigit != 0))
        triadWord += " рубля";
      else
        triadWord += " рублей";
    }

    triadWords.push_back(triadWord);
  }

  // Объединяем триады в одну строку
  for (int i = triadWords.size() - 1; i >= 0; --i) {
    result += triadWords[i];
    if (i > 0)
      result += " ";
  }

  return result;
}
