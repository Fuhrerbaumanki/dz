#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Fraction.h"
#include "Money.h"
#include "Pair.h"

class Application {
private:
  Pair *pairPointer;
  Money *moneyPointer;
  Fraction *fractionPointer;

public:
  Application();
  ~Application();

  void Run();

  void PairSubMenu();
  void MoneySubMenu();
  void FractionSubMenu();
};

#endif // APPLICATION_H
