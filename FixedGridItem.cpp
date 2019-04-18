// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(char symbol, int x, int y) : GridItem(symbol), x_(x), y_(y)
{
  assert(symbol && (!(x < 0 || x > SIZE || y < 0 || y > SIZE)));
}

int FixedGridItem::get_x() const
{
  assert(true);
  return x_;
}

int FixedGridItem::get_y() const
{
  assert(true);
  return y_;
}

bool FixedGridItem::is_at_position(int x, int y) const
{
  assert(!(x < 0 || x > SIZE || y < 0 || y > SIZE));
  return !(!(x_ == x) || !(y_ == y));
}