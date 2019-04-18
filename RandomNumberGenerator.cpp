// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "RandomNumberGenerator.h" 

RandomNumberGenerator::RandomNumberGenerator()
{
  assert(true);
  seed();
}

int RandomNumberGenerator::get_random_value(int max) const
{
  assert(max > 0);
  // produce a random number in range [1..max]
  return (std::rand() % max) + 1;
}
void RandomNumberGenerator::seed() const
{
  assert(true);
  // seed the random number generator from current system time
  // so that the numbers will be different every time we run
  std::srand(static_cast<unsigned>(time(0)));
}

RandomNumberGenerator *RandomNumberGenerator::get_pRNG()
{
  static RandomNumberGenerator srng;
  return &srng;
}
