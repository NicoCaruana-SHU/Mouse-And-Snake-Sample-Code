// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef MOVABLEGRIDITEM_H
#define MOVABLEGRIDITEM_H

#include <cassert>      // Used for debugging
#include "Constants.h"  // Used for debugging - Allows asserts to use SIZE ensure co-ordinates are within grid bounds

#include "GridItem.h"   // Parent Class
#include "RandomNumberGenerator.h"
#include "Underground.h"

// Parent class for items that can move on the grid, child of GridItem
class MovableGridItem : public GridItem
{
public:
  // Constructor
  MovableGridItem(const char symbol); // Nico - Using this constructor, the position is generated randomly
  MovableGridItem(const char symbol, int startingX, int startingY);

  // Public Methods
  int get_x() const;
  int get_y() const;
  bool is_at_position(const int x, const int y) const;
  void reset_position(const int x, const int y);
  void update_position(const int dx, const int dy);
  bool is_on_a_hole() const;
  void generate_new_random_position();
  void undo_move();
  bool undo_check();
private:
  // Attributes
  int x_, y_;
  int ox_, oy_; // last known positions of x and y
};

#endif // !MOVABLEGRIDITEM_H