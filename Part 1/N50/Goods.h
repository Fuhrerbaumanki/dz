#ifndef GOODS_H
#define GOODS_H

#include "Money.h"
#include <string>

class Goods {
private:
  std::string name;
  std::string date;
  Money price;
  int quantity;
  std::string invoiceNumber;

public:
  // Конструктор
  Goods(const std::string &n, const std::string &d, const Money &p, int q,
        const std::string &inv);

  // Методы для изменения цены товара
  void changePrice(const Money &newPrice);

  // Методы для увеличения и уменьшения количества товара
  void increaseQuantity(int amount);
  void decreaseQuantity(int amount);

  // Метод для вычисления стоимости товара
  Money calculateTotal() const;

  // Метод для вывода информации о товаре
  void displayInfo() const;
};

#endif // GOODS_H
