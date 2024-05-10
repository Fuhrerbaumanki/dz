#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Triangle.h"

class Application {
public:
  void Run();

private:
  void CreateTriangle(Triangle *&triangle);
  void GetSideLengths(const Triangle *triangle);
  void CalculatePerimeter(const Triangle *triangle);
  void CalculateArea(const Triangle *triangle);
  void CheckEquilateral(const Triangle *triangle);
  void CheckIsosceles(const Triangle *triangle);
  void CheckRight(const Triangle *triangle);
};

#endif
