#include "Bankomat.h"
#include <iostream>

Bankomat::Bankomat(int id, unsigned int minWithdrawal,
                   unsigned int maxWithdrawal)
    : atmId(id), minWithdrawalAmount(minWithdrawal),
      maxWithdrawalAmount(maxWithdrawal) {}

void Bankomat::loadMoney(int denomination, int count) {
  money.addDenomination(denomination, count);
}

bool Bankomat::withdrawMoney(unsigned int amount) {
  if (amount < minWithdrawalAmount || amount > maxWithdrawalAmount) {
    std::cerr << "Ошибка: Сумма снятия не входит в разрешенный диапазон."
              << std::endl;
    return false;
  }

  if (amount % 100 != 0) {
    std::cerr << "Ошибка: Сумма снятия должна быть кратна 100." << std::endl;
    return false;
  }

  Money amountToWithdraw = money / 100 * amount;
  if (amountToWithdraw == Money()) {
    std::cerr << "Ошибка: Недостаточно средств в банкомате." << std::endl;
    return false;
  }

  money = money - amountToWithdraw;
  std::cout << "Успешно снято " << amount << " рублей." << std::endl;
  return true;
}

void Bankomat::printAvailableMoney() const {
  std::cout << "ID банкомата: " << atmId << std::endl;
  std::cout << "Доступные средства в банкомате:" << std::endl;
  money.print();
}
