// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#ifndef GAME_H
#define GAME_H

#include <cassert>    // Used for debugging

#include <string>     // for string
#include <sstream>    // for stringstream

#include "Player.h"
#include "UserInterface.h"
#include "Underground.h"
#include "Nut.h"
#include "Mouse.h"
#include "Snake.h"

class Game
{
public:
  //Functions
  Game(Player *const pPlayer, const UserInterface *const ui);
  void run();

private:
  //Attributes
  Player *const pPlayer_;
  const UserInterface *const pUi_;	//removed pointer and included the UI object within the Game class - only the Game class currently references it
                      //the main only required to know about the UI for the declaration and hold screen
  const Underground* const pUnderground_;
  Nut nut_;
  Mouse mouse_;
  Snake snake_;
  bool cheatUsed;
  bool cheatActive;

  //Functions
  bool is_arrow_key_code(int keycode) const;
  bool has_ended(char key) const;
  std::string prepare_grid() const;          //TODO Nico - Tempted to move both of these functions into the UI class... game doesnt really want to deal with output messages if we have a UI to do that
  std::string prepare_end_message() const;   // Dont really need to generate the strings at runtime either, can use predefined ones and just select rather than going via osstream unless we use dynamic data

  void apply_rules();
  void apply_undo();

};
#endif
