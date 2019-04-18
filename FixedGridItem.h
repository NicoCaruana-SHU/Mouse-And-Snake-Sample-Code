// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef FIXEDGRIDITEM_H
#define FIXEDGRIDITEM_H

#include <cassert>      // Used for debugging
#include "Constants.h"  // Used for debugging - Allows asserts to use SIZE to ensure co-ordinates are within grid bounds

#include "GridItem.h"   // Parent Class

class FixedGridItem :
  public GridItem
{
public:
  FixedGridItem(char symbol, int x, int y);

  int get_x() const;
  int get_y() const;
  bool is_at_position(int x, int y) const;

private:
  const int x_;
  const int y_;
};

#endif // !FIXEDGRIDITEM_H
