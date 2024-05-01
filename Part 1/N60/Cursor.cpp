#include "Cursor.h"
#include <iostream>

Cursor::Cursor(LongLong horizontalCoords, LongLong verticalCoords,
               CursorType cursorType, int cursorSize)
    : horizontalCoordinate(horizontalCoords),
      verticalCoordinate(verticalCoords), type(cursorType), size(cursorSize) {}

void Cursor::moveCursor(LongLong newHorizontalCoords,
                        LongLong newVerticalCoords) {
  horizontalCoordinate = newHorizontalCoords;
  verticalCoordinate = newVerticalCoords;
}

void Cursor::changeCursorType(CursorType newType) { type = newType; }

void Cursor::changeCursorSize(int newSize) {
  if (newSize >= 1 && newSize <= 15)
    size = newSize;
  else
    std::cout << "Размер курсора должен быть от 1 до 15." << std::endl;
}

void Cursor::hideCursor() {
  // Типа скрыли курсор
  std::cout << "Курсор скрыт" << std::endl;
}

void Cursor::showCursor() {
  // Вроде как восстановили
  std::cout << "Курсор восстановлен" << std::endl;
}
