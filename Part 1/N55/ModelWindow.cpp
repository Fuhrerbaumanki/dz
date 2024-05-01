#include "ModelWindow.h"
#include <iostream>

ModelWindow::ModelWindow(const std::string &title, int x, int y, int width,
                         int height, const std::string &color,
                         WindowState state, BorderState border,
                         const Cursor &cursor)
    : title(title), left_top_x(x), left_top_y(y), width(width), height(height),
      color(color), state(state), border(border), cursor(cursor) {}

void ModelWindow::moveHorizontal(int delta) {
  int new_x = left_top_x + delta;
  if (new_x >= 0 && new_x + width <= 100) {
    left_top_x = new_x;
  }
}

void ModelWindow::moveVertical(int delta) {
  int new_y = left_top_y + delta;
  if (new_y >= 0 && new_y + height <= 50) {
    left_top_y = new_y;
  }
}

void ModelWindow::changeWidth(int new_width) {
  if (left_top_x + new_width <= 100) {
    width = new_width;
  }
}

void ModelWindow::changeHeight(int new_height) {
  if (left_top_y + new_height <= 50) {
    height = new_height;
  }
}

void ModelWindow::changeColor(const std::string &new_color) {
  color = new_color;
}

void ModelWindow::changeState(WindowState new_state) { state = new_state; }

void ModelWindow::changeBorder(BorderState new_border) { border = new_border; }

void ModelWindow::display() const {
  std::cout << "Заголовок: " << title << std::endl;
  std::cout << "Позиция: (" << left_top_x << ", " << left_top_y << ")"
            << std::endl;
  std::cout << "Размер: " << width << "x" << height << std::endl;
  std::cout << "Цвет: " << color << std::endl;
  std::cout << "Состояние: " << (state == VISIBLE ? "Видимый" : "Невидимый")
            << std::endl;
  std::cout << "Рамка: " << (border == WITH_BORDER ? "С рамкой" : "Без рамки")
            << std::endl;
  cursor.displayCursor();
}
