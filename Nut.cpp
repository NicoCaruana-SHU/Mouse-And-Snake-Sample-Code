// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "Nut.h"

Nut::Nut() : MovableGridItem(NUT), collected_(false)
{
  assert(true);
  while (is_on_a_hole() || on_edge())
  {
    generate_new_random_position();
  }
}

bool Nut::has_been_collected() const
{
  assert(true);
  return collected_;
}

void Nut::disappear()
{
  assert(true);
  collected_ = true;
}

void Nut::push(const int x, const int y)
{
  if (x != 0)
  {
    if (((this->get_x() + x) > 1) && ((this->get_x() + x) <= (SIZE - 1)))
    {
      update_position(x, 0);
    }
  }
  if (y != 0)
  {
    if (((this->get_y() + y) > 1) && ((this->get_y() + y) <= (SIZE - 1)))
    {
      update_position(0, y);
    }
  }
}

bool Nut::on_edge()
{
  bool onEdge = false;
  if (this->get_x() == 1 || this->get_x() == SIZE)
  {
    onEdge = true;
  }
  else if (this->get_y() == 1 || this->get_y() == SIZE)
  {
    onEdge = true;
  }

  return onEdge;
}