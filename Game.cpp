// CS4G Group 11
// Matthew Bellamy, Connor Bingham, Nico Caruana, Shannon Higgins
#include "Game.h"

Game::Game(Player *const pPlayer, const UserInterface *const ui) : pPlayer_(pPlayer), pUi_(ui), pUnderground_(Underground::get_pUg()), nut_(), mouse_(&nut_), snake_(&mouse_, &nut_) //the constructor - you would've needed to setup the game every time you created one, so made sense to just have this as the constructor
{
  assert(pPlayer != nullptr);
}

void Game::run()
{
  assert(true);

  (*pUi_).draw_grid_on_screen(prepare_grid());
  (*pUi_).display_score_name((*pPlayer_).get_score(), (*pPlayer_).get_name()); //gets score from player and then pass the value to the UI

  int key = (*pUi_).get_keypress_from_user();
  while (!has_ended(key))
  {
    if (is_arrow_key_code(key))
    {
      mouse_.scamper(key);
      if (!cheatActive)
      {
        snake_.chase_mouse();
      }
      (*pUi_).draw_grid_on_screen(prepare_grid());
      apply_rules();
      (*pUi_).display_score_name((*pPlayer_).get_score(), (*pPlayer_).get_name()); //gets score from player and then pass the value to the UI
      if (cheatActive)
      {
        (*pUi_).cheat_message();
      }
    }
    else
    {
      if (key == UNDO)
      {
        if (mouse_.undo_check())
        {
          apply_undo();
          (*pUi_).draw_grid_on_screen(prepare_grid());
          (*pUi_).display_score_name((*pPlayer_).get_score(), (*pPlayer_).get_name());
          if (cheatActive)
          {
            (*pUi_).cheat_message();
          }
        }
        else {
          (*pUi_).undo_error_display();
        }
      }
      else if (key == CHEAT)
      {
        cheatActive = !cheatActive;
        cheatUsed = true;
        if (cheatActive)
        {
          (*pUi_).cheat_message();
        }
      }
    }
    key = (*pUi_).get_keypress_from_user();


  }
  (*pUi_).show_results_on_screen(prepare_end_message());

}

std::string Game::prepare_grid() const
{
  assert(true);
  // this function builds up a big string which holds the entire game state

  std::ostringstream os;
  int tail_segments_prepared = 0;
  for (int row(1); row <= SIZE; ++row)
  {
    for (int col(1); col <= SIZE; ++col)
    {
      if ((row == snake_.get_y()) && (col == snake_.get_x()))
      {
        os << snake_.get_symbol();
      }
      else
      {
        if (snake_.tail_segment_at_position(col, row))
        {
          os << snake_.get_tail_symbol_at(tail_segments_prepared);
          ++tail_segments_prepared;
        }
        else
        {
          if (mouse_.is_at_position(col, row))
          {
            os << mouse_.get_symbol();
          }
          else
          {
            const int hole_no(pUnderground_->get_hole_index(col, row));
            if (hole_no != -1)
              os << pUnderground_->get_hole_symbol(hole_no);
            else {
              if (!nut_.has_been_collected() && nut_.is_at_position(col, row))
              {
                os << nut_.get_symbol();
              }
              else
              {
                os << FREECELL;
              }
            }
          }
        }
      }
    }
    os << std::endl;
  }
  return os.str();
}

bool Game::is_arrow_key_code(int keycode) const
{
  assert(keycode);
  return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

void Game::apply_rules()
{
  assert(true);
  if (snake_.has_caught_mouse())
  {
    mouse_.die();
    (*pPlayer_).update_score(-1);
  }
  else {
    if (nut_.is_on_a_hole())
    {
      nut_.disappear();
    }
    if (mouse_.is_on_a_hole())
    {
      if (nut_.has_been_collected())
      {
        mouse_.escape_into_hole();
      }
      else
      {
        mouse_.tunnel_hole();
      }
      if (!cheatUsed)
      {
        (*pPlayer_).update_score(1);
      }
    }
  }
}

bool Game::has_ended(char key) const
{
  assert(key);
  return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

std::string Game::prepare_end_message() const
{
  assert(true);
  std::ostringstream os;
  if (mouse_.has_escaped())
  {
    os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
  }
  else
  {
    if (!mouse_.is_alive())
    {
      os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
    }
    else
    {
      os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
    }
  }
  return os.str();
}


void Game::apply_undo()
{
  mouse_.undo_move();
  snake_.undo_move(cheatActive);
  nut_.undo_move();
}
