#include "Goods.h"

// Конструктор по умолчанию
Goods::Goods() : price(0.0), quantity(0) {}

// Конструктор с параметрами
Goods::Goods(const std::string &_name, const Date &_dateOfArrival,
             double _price, unsigned int _quantity,
             const std::string &_invoiceNumber)
    : name(_name), dateOfArrival(_dateOfArrival), price(_price),
      quantity(_quantity), invoiceNumber(_invoiceNumber) {}

// Метод изменения цены товара
void Goods::changePrice(double newPrice) { price = newPrice; }

// Метод увеличения количества товара
void Goods::increaseQuantity(unsigned int amount) { quantity += amount; }

// Метод уменьшения количества товара
void Goods::decreaseQuantity(unsigned int amount) {
  if (amount <= quantity) {
    quantity -= amount;
  } else {
    std::cerr << "Error: Trying to decrease quantity by more than available.\n";
  }
}

// Метод вычисления стоимости товара
double Goods::calculateTotalCost() const { return price * quantity; }

std::string numberToWords(int number) {
  // Массивы слов для чисел от 0 до 19
  std::string units[] = {"",
                         "один",
                         "два",
                         "три",
                         "четыре",
                         "пять",
                         "шесть",
                         "семь",
                         "восемь",
                         "девять",
                         "десять",
                         "одиннадцать",
                         "двенадцать",
                         "тринадцать",
                         "четырнадцать",
                         "пятнадцать",
                         "шестнадцать",
                         "семнадцать",
                         "восемнадцать",
                         "девятнадцать"};

  // Массивы слов для десятков
  std::string tens[] = {
      "",          "",           "двадцать",  "тридцать",    "сорок",
      "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};

  if (number < 20) {
    return units[number];
  } else if (number < 100) {
    return tens[number / 10] +
           ((number % 10 != 0) ? " " + units[number % 10] : "");
  } else if (number < 1000) {
    return units[number / 100] + "сот" +
           ((number % 100 != 0) ? " " + numberToWords(number % 100) : "");
  } else if (number < 1000000) {
    return numberToWords(number / 1000) + " тысяч" +
           ((number % 1000 != 0) ? " " + numberToWords(number % 1000) : "");
  } else {
    return "Число слишком большое";
  }
}

std::string Goods::toString() const {
  double cost = calculateTotalCost();
  int rubles = static_cast<int>(cost);
  int kopecks = static_cast<int>((cost - rubles) * 100);

  std::string result = numberToWords(rubles) + " рублей";

  if (kopecks != 0) {
    result += " " + numberToWords(kopecks) + " копеек";
  }

  return result;
}

unsigned int Goods::calculateStoragePeriod(const Date &currentDate) const {
  // Вычисляем разницу между текущей датой и датой поступления товара
  unsigned int storageDays = currentDate.daysBetween(dateOfArrival);
  return storageDays;
}
