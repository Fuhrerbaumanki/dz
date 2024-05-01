#pragma once
#ifndef SET_H
#define SET_H

#include "BitString.h"

class Set {
private:
  BitString bits;

public:
  Set();

  void add(int num);

  void remove(int num);

  Set unionWith(const Set &other) const;

  Set intersectionWith(const Set &other) const;

  Set differenceWith(const Set &other) const;

  int count() const;

  void display() const;
};

#endif // SET_H
