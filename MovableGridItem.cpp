// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "MovableGridItem.h"

MovableGridItem::MovableGridItem(const char symbol) : GridItem(symbol), x_(RandomNumberGenerator::get_pRNG()->get_random_value(SIZE)), y_(RandomNumberGenerator::get_pRNG()->get_random_value(SIZE)), ox_(x_), oy_(y_)
{

}

// Constructor. First builds as a GridItem, then fills in new bits, with given input
// PRECON: Provided symbol is not null
MovableGridItem::MovableGridItem(const char symbol, const int startingX, const int startingY) : GridItem(symbol), x_(startingX), y_(startingY)
{
  assert(symbol && (!(startingX < 0 || startingX > SIZE || startingY < 0 || startingY > SIZE)));
}

// Returns the item's x-position
// PRECON: N/A
int MovableGridItem::get_x() const
{
  assert(true);

  return x_;
}

// Returns the item's y-position
// PRECON: N/A
int MovableGridItem::get_y() const
{
  assert(true);

  return y_;
}

// Returns true if this item is at the given xy coordinates, otherwise returns false
// PRECON: x and y are not negative values since negatives mean nothing to the grid coordinates
bool MovableGridItem::is_at_position(const int x, const int y) const
{
  assert(!(x < 0 || x > SIZE || y < 0 || y > SIZE));

  return !(x_ != x || y_ != y);
}

// Resets the item's position to a given set of xy coordinates so long as it is within the boundaries of the play area
// PRECON: x and y do not go below or over the boundaries of the play area
void MovableGridItem::reset_position(const int x, const int y)
{
  assert(!(x < 0 || x > SIZE || y < 0 || y > SIZE));

  x_ = x;
  y_ = y;
}

// Changes the objects xy position relative to its current position
// PRECON: dx and dy would not take the item out of the play area
void MovableGridItem::update_position(const int dx, const int dy)
{
  assert(true);
  if ((x_ + dx > 0) && (x_ + dx <= SIZE))
  {
    ox_ = x_;
    x_ += dx;
  }
  if ((y_ + dy > 0) && (y_ + dy <= SIZE))
  {
    oy_ = y_;
    y_ += dy;
  }
}

bool MovableGridItem::is_on_a_hole() const
{
  assert(true);
  return Underground::get_pUg()->get_hole_index(get_x(), get_y()) != -1;
}

void MovableGridItem::generate_new_random_position()
{
  reset_position(RandomNumberGenerator::get_pRNG()->get_random_value(SIZE), RandomNumberGenerator::get_pRNG()->get_random_value(SIZE));
}

void MovableGridItem::undo_move()
{
  x_ = ox_;
  y_ = oy_;
}

bool MovableGridItem::undo_check()
{
  return !((x_ == ox_) && (y_ == oy_));
}