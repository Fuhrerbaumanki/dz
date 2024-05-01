#include "Cursor.h"
#include <iostream>

Cursor::Cursor(int h_pos, int v_pos, CursorType type, int size)
    : horizontal_pos(h_pos), vertical_pos(v_pos), cursor_type(type),
      cursor_size(size) {}

void Cursor::moveCursor(int new_h_pos, int new_v_pos) {
  horizontal_pos = new_h_pos;
  vertical_pos = new_v_pos;
}

void Cursor::changeCursorType(CursorType new_type) { cursor_type = new_type; }

void Cursor::changeCursorSize(int new_size) {
  if (new_size >= 1 && new_size <= 15) {
    cursor_size = new_size;
  }
}

void Cursor::eraseCursor() {
  // Типа стираем курсор (ХЗ как это сделать)
  std::cout << "Кусор стёрт" << std::endl;
}

void Cursor::restoreCursor() {
  // Нууу типа восстанавливаем
  std::cout << "Курсор восстановлен" << std::endl;
}

void Cursor::displayCursor() const {
  std::cout << "Горизонтальная позиция: " << horizontal_pos << std::endl;
  std::cout << "Вертикальная позиция: " << vertical_pos << std::endl;
  std::cout << "Тип курсора: "
            << (cursor_type == HORIZONTAL ? "Горизонтальный" : "Вертикальный")
            << std::endl;
  std::cout << "Размер курсора: " << cursor_size << std::endl;
}
