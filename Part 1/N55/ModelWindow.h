#ifndef MODELWINDOW_H
#define MODELWINDOW_H

#include "Cursor.h"
#include <string>

enum WindowState { VISIBLE, INVISIBLE };

enum BorderState { WITH_BORDER, WITHOUT_BORDER };

class ModelWindow {
private:
  std::string title;
  int left_top_x;
  int left_top_y;
  int width;
  int height;
  std::string color;
  WindowState state;
  BorderState border;
  Cursor cursor;

public:
  ModelWindow(const std::string &title, int x, int y, int width, int height,
              const std::string &color, WindowState state, BorderState border,
              const Cursor &cursor);

  void moveHorizontal(int delta);
  void moveVertical(int delta);
  void changeWidth(int new_width);
  void changeHeight(int new_height);
  void changeColor(const std::string &new_color);
  void changeState(WindowState new_state);
  void changeBorder(BorderState new_border);

  void display() const;
};

#endif // MODELWINDOW_H
