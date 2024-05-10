#include "Application_triangle.h"
#include <iostream>

void Application::Run() {
  int choice;
  Triangle *triangle = nullptr;
  while (true) {
    std::cout << "Triangle Menu:" << std::endl;
    std::cout << "1. Create Triangle" << std::endl;
    std::cout << "2. Get side lengths" << std::endl;
    std::cout << "3. Calculate perimeter" << std::endl;
    std::cout << "4. Calculate area" << std::endl;
    std::cout << "5. Check if equilateral" << std::endl;
    std::cout << "6. Check if isosceles" << std::endl;
    std::cout << "7. Check if right" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      CreateTriangle(triangle);
      break;
    case 2:
      GetSideLengths(triangle);
      break;
    case 3:
      CalculatePerimeter(triangle);
      break;
    case 4:
      CalculateArea(triangle);
      break;
    case 5:
      CheckEquilateral(triangle);
      break;
    case 6:
      CheckIsosceles(triangle);
      break;
    case 7:
      CheckRight(triangle);
      break;
    case 8:
      delete triangle; // Free allocated memory
      return;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
    }
  }
}

void Application::CreateTriangle(Triangle *&triangle) {
  double p1, p2, p3;
  std::cout << "Enter coordinates of point 1 (x y): ";
  std::cin >> p1;
  std::cout << "Enter coordinates of point 2 (x y): ";
  std::cin >> p2;
  std::cout << "Enter coordinates of point 3 (x y): ";
  std::cin >> p3;
  triangle = new Triangle(Point(p1, p2), Point(p2, p2), Point(p3, p3));
}

void Application::GetSideLengths(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Side 1 length: " << triangle->get_side1() << std::endl;
    std::cout << "Side 2 length: " << triangle->get_side2() << std::endl;
    std::cout << "Side 3 length: " << triangle->get_side3() << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}

void Application::CalculatePerimeter(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Perimeter: " << triangle->perimeter() << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}

void Application::CalculateArea(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Area: " << triangle->area() << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}

void Application::CheckEquilateral(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Is equilateral: "
              << (triangle->is_equilateral() ? "Yes" : "No") << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}

void Application::CheckIsosceles(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Is isosceles: " << (triangle->is_isosceles() ? "Yes" : "No")
              << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}

void Application::CheckRight(const Triangle *triangle) {
  if (triangle) {
    std::cout << "Is right: " << (triangle->is_right() ? "Yes" : "No")
              << std::endl;
  } else {
    std::cout << "Triangle not created yet." << std::endl;
  }
}
