#pragma once
#include "Date.h" // Подключаем заголовок класса Date
#include <iostream>
#include <string>

class Goods {
private:
  std::string name;
  Date dateOfArrival; // Дата поступления товара на склад
  double price;
  unsigned int quantity;
  std::string invoiceNumber;

public:
  // Конструкторы
  Goods();
  Goods(const std::string &_name, const Date &_dateOfArrival, double _price,
        unsigned int _quantity, const std::string &_invoiceNumber);

  // Методы изменения цены товара
  void changePrice(double newPrice);

  // Методы увеличения и уменьшения количества товара
  void increaseQuantity(unsigned int amount);
  void decreaseQuantity(unsigned int amount);

  // Метод вычисления стоимости товара
  double calculateTotalCost() const;

  // Метод для получения текстового представления стоимости товара
  std::string toString() const;

  // Метод вычисления срока хранения товара в днях
  unsigned int calculateStoragePeriod(const Date &currentDate) const;
};
