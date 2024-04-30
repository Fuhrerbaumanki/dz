#include <iostream>
#include <string>

// Вспомогательный класс Money
class Money {
private:
  int rubles; // Рубли
  int kopeks; // Копейки

public:
  Money(int rubles = 0, int kopeks = 0) : rubles(rubles), kopeks(kopeks) {}

  // Перегруженный оператор вывода для печати денежной суммы
  friend std::ostream &operator<<(std::ostream &os, const Money &money) {
    os << money.rubles << ",";
    if (money.kopeks < 10)
      os << "0"; // Выводим ведущий ноль для однозначных копеек
    os << money.kopeks;
    return os;
  }

  // Метод для получения суммы прописью
  std::string amountInWords() const {
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

    int rubles_units = rubles % 10;
    int rubles_tens = (rubles % 100) / 10;
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

    if (kopeks > 0) {
      int kopeks_units = kopeks % 10;
      int kopeks_tens = (kopeks % 100) / 10;
      result +=
          " " + tens[kopeks_tens - 1] + " " + ones[kopeks_units] + " копеек";
    }

    return result;
  }
};

class Account {
private:
  std::string ownerLastName; // Фамилия владельца
  std::string accountNumber; // Номер счёта
  float interestRate;        // Процент начисления
  Money balance;             // Сумма на счете

public:
  // Конструктор для открытия нового счёта
  Account(const std::string &ownerLastName, const std::string &accountNumber,
          float interestRate, const Money &initialBalance)
      : ownerLastName(ownerLastName), accountNumber(accountNumber),
        interestRate(interestRate), balance(initialBalance) {}

  // Метод для смены владельца счёта
  void changeOwner(const std::string &newOwnerLastName) {
    ownerLastName = newOwnerLastName;
  }

  // Метод для снятия суммы
  void withdraw(const Money &amount) {
    if (balance < amount) {
      std::cout << "Недостаточно средств на счете" << std::endl;
    } else {
      balance = balance - amount;
      std::cout << "Сумма " << amount << " успешно снята" << std::endl;
    }
  }

  // Метод для внесения суммы
  void deposit(const Money &amount) {
    balance = balance + amount;
    std::cout << "Сумма " << amount << " успешно внесена" << std::endl;
  }

  // Метод для начисления процентов
  void addInterest() {
    Money interest = balance * (interestRate / 100);
    balance = balance + interest;
    std::cout << "Проценты успешно начислены" << std::endl;
  }

  // Метод для перевода суммы в доллары
  Money toDollars(float exchangeRate) const {
    float dollars = balance / exchangeRate;
    int rubles = static_cast<int>(dollars);
    int kopeks = static_cast<int>((dollars - rubles) * 100);
    return Money(rubles, kopeks);
  }

  // Метод для перевода суммы в евро
  Money toEuro(float exchangeRate) const {
    float euro = balance / exchangeRate;
    int rubles = static_cast<int>(euro);
    int kopeks = static_cast<int>((euro - rubles) * 100);
    return Money(rubles, kopeks);
  }

  // Метод для получения суммы на счете
  Money getBalance() const { return balance; }

  // Метод для вывода суммы прописью
  std::string balanceInWords() const { return balance.amountInWords(); }
};
