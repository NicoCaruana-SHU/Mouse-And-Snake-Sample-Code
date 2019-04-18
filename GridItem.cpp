// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "GridItem.h"

GridItem::GridItem(const char symbol) : symbol_(symbol)
{
  assert(symbol);
}

char GridItem::get_symbol() const
{
  assert(true);
  return symbol_;
}
