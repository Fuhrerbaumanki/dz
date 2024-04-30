#pragma once
#ifndef BANKOMAT_H
#define BANKOMAT_H

#include "Money.h"

class Bankomat {
private:
  int atmId;
  Money money;
  unsigned int minWithdrawalAmount;
  unsigned int maxWithdrawalAmount;

public:
  Bankomat(int id, unsigned int minWithdrawal, unsigned int maxWithdrawal);

  void loadMoney(int denomination, int count);
  bool withdrawMoney(unsigned int amount); // Метод снятия денег

  void printAvailableMoney() const; // Метод для вывода доступных денег
};

#endif // BANKOMAT_H
