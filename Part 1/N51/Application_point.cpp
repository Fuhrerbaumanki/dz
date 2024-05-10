#include "Application_point.h"
#include <iostream>

void Application::run() {
  int choice;
  while (true) {
    std::cout << "Menu:\n";
    std::cout << "1. Create a point\n";
    std::cout << "2. Move the point\n";
    std::cout << "3. Calculate distance to origin\n";
    std::cout << "4. Calculate distance to another point\n";
    std::cout << "5. Convert point to polar coordinates\n";
    std::cout << "6. Check equality of points\n";
    std::cout << "7. Print total count of points\n";
    std::cout << "8. Reset count of points\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      point = *createPoint();
      break;
    case 2:
      movePoint();
      break;
    case 3:
      calculateDistanceToOrigin();
      break;
    case 4:
      calculateDistanceToAnotherPoint();
      break;
    case 5:
      convertToPolarCoordinates();
      break;
    case 6:
      checkPointEquality();
      break;
    case 7:
      printTotalPointCount();
      break;
    case 8:
      resetPointCount();
      break;
    case 9:
      std::cout << "Exiting...\n";
      return;
    default:
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
  }
}

Point *Application::createPoint() {
  double x, y;
  std::cout << "Enter x coordinate: ";
  std::cin >> x;
  std::cout << "Enter y coordinate: ";
  std::cin >> y;
  return new Point(x, y);
}

void Application::movePoint() {
  double dx, dy;
  std::cout << "Enter displacement in x direction: ";
  std::cin >> dx;
  std::cout << "Enter displacement in y direction: ";
  std::cin >> dy;
  point.move_x(dx);
  point.move_y(dy);
  std::cout << "Point moved.\n";
}

void Application::calculateDistanceToOrigin() {
  double distance = point.distance_to_origin();
  std::cout << "Distance to origin: " << distance << std::endl;
}

void Application::calculateDistanceToAnotherPoint() {
  double distance = point1.distance_to_point(point2);
  std::cout << "Distance between points: " << distance << std::endl;
}

void Application::convertToPolarCoordinates() {
  auto polar = point.to_polar();
  std::cout << "Polar coordinates: (" << polar.first << ", " << polar.second
            << ")\n";
}

void Application::checkPointEquality() {
  if (point1 == point2) {
    std::cout << "Points are equal.\n";
  } else {
    std::cout << "Points are not equal.\n";
  }
}

void Application::printTotalPointCount() {
  std::cout << "Total count of points: " << Point::getCount() << std::endl;
}

void Application::resetPointCount() {
  Point::resetCount();
  std::cout << "Point count reset.\n";
}
