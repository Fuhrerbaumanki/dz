#include "Application.h"
#include <iostream>

Application::Application() {
  // Инициализация, если необходимо
}

Application::~Application() {
  // Освобождаем память, занятую массивами
  for (Array *array : arrays) {
    delete array;
  }
}

void Application::printMenu() {
  std::cout << "Menu:\n";
  std::cout << "1. Hex Operations\n";
  std::cout << "2. Octal Operations\n";
  std::cout << "3. Add Arrays\n";
  std::cout << "4. Display Array\n";
  std::cout << "5. Exit\n";
  std::cout << "Choose an option: ";
}

void Application::handleOption(int option) {
  switch (option) {
  case 1: {
    hexMenu();
    break;
  }
  case 2: {
    octalMenu();
    break;
  }
  case 3: {
    if (arrays.size() < 2) {
      std::cout << "At least two arrays are required to perform addition.\n";
      break;
    }
    Array *array1 = arrays[arrays.size() - 2];
    Array *array2 = arrays[arrays.size() - 1];
    Array *result = array1->add(*array2);
    arrays.push_back(result);
    std::cout << "Arrays added. Result stored as a new array.\n";
    break;
  }
  case 4: {
    if (arrays.empty()) {
      std::cout << "No arrays to display.\n";
      break;
    }
    int index;
    std::cout << "Enter index of array to display (0 to " << arrays.size() - 1
              << "): ";
    std::cin >> index;
    if (index < 0 || index >= arrays.size()) {
      std::cout << "Invalid index.\n";
      break;
    }
    std::cout << "Array content: ";
    for (size_t i = 0; i < arrays[index]->getSize(); ++i) {
      std::cout << static_cast<int>((*arrays[index])[i]) << " ";
    }
    std::cout << "\n";
    break;
  }
  case 5: {
    std::cout << "Exiting...\n";
    break;
  }
  default: {
    std::cout << "Invalid option. Please try again.\n";
  }
  }
}

void Application::hexMenu() {
  int size;
  std::cout << "Enter size of Hex array: ";
  std::cin >> size;
  Hex *hexArray = new Hex(size);
  arrays.push_back(hexArray);

  int option = 0;
  while (option != 5) {
    printHexMenu();
    std::cin >> option;
    handleHexOption(option, hexArray);
  }
}

void Application::octalMenu() {
  int size;
  std::cout << "Enter size of Octal array: ";
  std::cin >> size;
  Octal *octalArray = new Octal(size);
  arrays.push_back(octalArray);

  int option = 0;
  while (option != 5) {
    printOctalMenu();
    std::cin >> option;
    handleOctalOption(option, octalArray);
  }
}

void Application::printHexMenu() {
  std::cout << "Hex Menu:\n";
  std::cout << "1. Set Digit\n";
  std::cout << "2. Get Digit\n";
  std::cout << "3. Display Array\n";
  std::cout << "4. Back to Main Menu\n";
  std::cout << "Choose an option: ";
}

void Application::printOctalMenu() {
  std::cout << "Octal Menu:\n";
  std::cout << "1. Set Digit\n";
  std::cout << "2. Get Digit\n";
  std::cout << "3. Display Array\n";
  std::cout << "4. Back to Main Menu\n";
  std::cout << "Choose an option: ";
}

void Application::handleHexOption(int option, Hex *hexArray) {
  switch (option) {
  case 1: {
    int index;
    unsigned char value;
    std::cout << "Enter index: ";
    std::cin >> index;
    std::cout << "Enter value: ";
    std::cin >> value;
    if (hexArray->setDigit(index, value) == 0) {
      std::cout << "Value set successfully.\n";
    } else {
      std::cout << "Error setting value.\n";
    }
    break;
  }
  case 2: {
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    try {
      unsigned char value = hexArray->getDigit(index);
      std::cout << "Value at index " << index << ": " << static_cast<int>(value)
                << "\n";
    } catch (const std::out_of_range &e) {
      std::cout << e.what() << "\n";
    }
    break;
  }
  case 3: {
    std::cout << "Hex array content: ";
    for (size_t i = 0; i < hexArray->getSize(); ++i) {
      std::cout << std::hex << static_cast<int>((*hexArray)[i]) << " ";
    }
    std::cout << "\n";
    break;
  }
  case 4: {
    std::cout << "Returning to main menu.\n";
    return;
  }
  default: {
    std::cout << "Invalid option. Please try again.\n";
  }
  }
}

void Application::handleOctalOption(int option, Octal *octalArray) {
  switch (option) {
  case 1: {
    int index;
    unsigned char value;
    std::cout << "Enter index: ";
    std::cin >> index;
    std::cout << "Enter value: ";
    std::cin >> value;
    if (octalArray->setDigit(index, value) == 0) {
      std::cout << "Value set successfully.\n";
    } else {
      std::cout << "Error setting value.\n";
    }
    break;
  }
  case 2: {
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    try {
      unsigned char value = octalArray->getDigit(index);
      std::cout << "Value at index " << index << ": " << static_cast<int>(value)
                << "\n";
    } catch (const std::out_of_range &e) {
      std::cout << e.what() << "\n";
    }
    break;
  }
  case 3: {
    std::cout << "Octal array content: ";
    for (size_t i = 0; i < octalArray->getSize(); ++i) {
      std::cout << std::oct << static_cast<int>((*octalArray)[i]) << " ";
    }
    std::cout << "\n";
    break;
  }
  case 4: {
    std::cout << "Returning to main menu.\n";
    return;
  }
  default: {
    std::cout << "Invalid option. Please try again.\n";
  }
  }
}

void Application::Run() {
  int option = 0;
  while (option != 5) {
    printMenu();
    std::cin >> option;
    handleOption(option);
  }
}
