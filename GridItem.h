// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef GRIDITEM_H
#define GRIDITEM_H

#include <cassert>      // Used for debugging

class GridItem
{
public:
  GridItem(const char symbol);

  char get_symbol() const;

private:
  const char symbol_;
};

#endif // !GRIDITEM_H