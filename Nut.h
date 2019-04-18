// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef NUT_H
#define NUT_H

#include <cassert>            // Used for debugging

#include "Constants.h"        // Used for getting the NUT symbol & Allows asserts to use SIZE ensure co-ordinates are within grid bounds
#include "MovableGridItem.h"  // Parent Class

class Nut :
  public MovableGridItem //Nico - Doing this as moveable since it will need to be moved in the extension tasks
{
public:
  Nut();

  bool has_been_collected() const;
  void disappear();
  void push(const int x, const int y);

private:
  bool collected_;
  bool on_edge();
};

#endif // !NUT_H