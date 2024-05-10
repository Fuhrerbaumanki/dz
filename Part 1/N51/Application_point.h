#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Point.h"

class Application {
public:
  void run();

private:
  Point *createPoint();
  void movePoint();
  void calculateDistanceToOrigin();
  void calculateDistanceToAnotherPoint();
  void convertToPolarCoordinates();
  void checkPointEquality();
  void printTotalPointCount();
  void resetPointCount();

  Point point;
  Point point1;
  Point point2;
};

#endif
