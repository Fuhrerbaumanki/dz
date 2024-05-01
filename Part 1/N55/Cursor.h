#pragma once
#ifndef CURSOR_H
#define CURSOR_H

enum CursorType { HORIZONTAL, VERTICAL };

class Cursor {
private:
  int horizontal_pos;
  int vertical_pos;
  CursorType cursor_type;
  int cursor_size;

public:
  Cursor(int h_pos, int v_pos, CursorType type, int size);

  void moveCursor(int new_h_pos, int new_v_pos);
  void changeCursorType(CursorType new_type);
  void changeCursorSize(int new_size);
  void eraseCursor();
  void restoreCursor();

  // Для демонстрационных целей
  void displayCursor() const;
};

#endif // CURSOR_H
