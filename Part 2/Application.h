#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Array.h"
#include "Hex.h"
#include "Octal.h"
#include <iostream>
#include <vector>

class Application {
private:
  std::vector<Array *> arrays;

  void printMenu();
  void handleOption(int option);

  void hexMenu();
  void octalMenu();

  void printHexMenu();
  void printOctalMenu();

  void handleHexOption(int option, Hex *hexArray);
  void handleOctalOption(int option, Octal *octalArray);

public:
  Application();
  ~Application();

  void Run();
};

#endif // APPLICATION_H
