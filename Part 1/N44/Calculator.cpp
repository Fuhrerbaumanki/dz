#include "Calculator.h"
#include "Fraction.h"
#include <iostream>

Calculator::Calculator()
    : fraction(0, 0) {} // Конструктор по умолчанию с инициализацией Fraction

// Метод для установки значения дроби
void Calculator::setFraction(int64_t whole, uint16_t fractionPart) {
  fraction = Fraction(whole, fractionPart);
}

// Метод для выполнения операции сложения с другой дробью
void Calculator::add(const Fraction &other) { fraction = fraction + other; }

// Метод для выполнения операции вычитания с другой дробью
void Calculator::subtract(const Fraction &other) {
  fraction = fraction - other;
}

// Метод для выполнения операции умножения на другую дробь
void Calculator::multiply(const Fraction &other) {
  fraction = fraction * other;
}

// Метод для вывода значения текущей дроби
void Calculator::printFraction() const {
  std::cout << "Current fraction: " << fraction.getWholePart() << "."
            << fraction.getFractionPart() << std::endl;
}
