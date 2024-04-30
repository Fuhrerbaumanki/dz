#include "Goods.h"
#include <iostream>
#include <string>

// Конструктор
Goods::Goods(const std::string &n, const std::string &d, const Money &p, int q,
             const std::string &inv)
    : name(n), date(d), price(p), quantity(q), invoiceNumber(inv) {}

// Методы для изменения цены товара
void Goods::changePrice(const Money &newPrice) { price = newPrice; }

// Методы для увеличения и уменьшения количества товара
void Goods::increaseQuantity(int amount) { quantity += amount; }

void Goods::decreaseQuantity(int amount) {
  if (quantity >= amount)
    quantity -= amount;
  else
    std::cerr << "Ошибка: Количество не может быть ниже 0.\n";
}

// Метод для вычисления стоимости товара
Money Goods::calculateTotal() const { return price * quantity; }

// Метод для вывода информации о товаре
void Goods::displayInfo() const {
  std::cout << "Название: " << name << std::endl;
  std::cout << "Дата поступления: " << date << std::endl;
  std::cout << "Цена: ";
  price.display();
  std::cout << std::endl;
  std::cout << "Кол-во: " << quantity << std::endl;
  std::cout << "Номер накладной: " << invoiceNumber << std::endl;
}
