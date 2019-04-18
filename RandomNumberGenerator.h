// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef RandomNumberGenerator_H 
#define RandomNumberGenerator_H 

#include <cassert>  // Used for debugging

#include <cstdlib>  // Changed include from stdlb.h to remove unnecessary global name definitions
#include <ctime>    // for time used in RandomNumberGenerator::seed routines

class RandomNumberGenerator
{
public:
  static RandomNumberGenerator *get_pRNG(); //By creating it static in this way, it allows any object to use it, extension tasks!
  int get_random_value(int) const;

private:
  RandomNumberGenerator();
  void seed() const;
};
#endif