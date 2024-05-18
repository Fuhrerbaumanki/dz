#include "Application.h"
#include <iostream>

Application::Application()
    : pairPointer(nullptr), moneyPointer(nullptr), fractionPointer(nullptr) {
  // Создание объектов классов Money и Fraction
  moneyPointer = new Money();
  fractionPointer = new Fraction();
}

Application::~Application() {
  // Освобождение выделенной памяти при удалении объекта Application
  delete pairPointer;
  delete moneyPointer;
  delete fractionPointer;
}

void Application::Run() {
  // Пример простого меню для демонстрации работы с полиморфизмом

  while (true) {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Work with Pair" << std::endl;
    std::cout << "2. Work with Money" << std::endl;
    std::cout << "3. Work with Fraction" << std::endl;
    std::cout << "4. Exit" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      PairSubMenu();
      break;
    case 2:
      MoneySubMenu();
      break;
    case 3:
      FractionSubMenu();
      break;
    case 4:
      std::cout << "Exiting..." << std::endl;
      return;
    default:
      std::cout << "Invalid choice. Please enter a number from 1 to 4."
                << std::endl;
    }
  }
}

void Application::PairSubMenu() {
  std::cout << "Pair Submenu:" << std::endl;
  Pair *pairPointer = new Money(); // Money - производный от Pair класс
  pairPointer->print(std::cout);
  std::cout << std::endl;
  delete pairPointer; // Освобождение памяти
}

void Application::MoneySubMenu() {
  std::cout << "Money Submenu:" << std::endl;
  // Пример работы с объектом класса Money через указатель на базовый класс
  moneyPointer->print(std::cout); // Вызов виртуального метода из класса Money
  std::cout << std::endl;
}

void Application::FractionSubMenu() {
  std::cout << "Fraction Submenu:" << std::endl;
  // Пример работы с объектом класса Fraction через указатель на базовый класс
  fractionPointer->print(
      std::cout); // Вызов виртуального метода из класса Fraction
  std::cout << std::endl;
}
