#pragma once
#ifndef CURSOR_H
#define CURSOR_H

#include "LongLong.h"

enum CursorType { HORIZONTAL, VERTICAL }; // Виды курсора

class Cursor {
private:
  LongLong horizontalCoordinate;
  LongLong verticalCoordinate;
  CursorType type;
  int size;

public:
  Cursor(LongLong horizontalCoords, LongLong verticalCoords,
         CursorType cursorType, int cursorSize);

  // Методы изменения координат курсора
  void moveCursor(LongLong newHorizontalCoords, LongLong newVerticalCoords);

  // Метод изменения вида курсора
  void changeCursorType(CursorType newType);

  // Метод изменения размера курсора
  void changeCursorSize(int newSize);

  // Метод гашения курсора
  void hideCursor();

  // Метод восстановления курсора
  void showCursor();
};

#endif // CURSOR_H
