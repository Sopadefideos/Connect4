#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "state.h"

class Game {
  Board *board;
  State *state;
  int size;
  int nrows;
  int ncols;
  string player1, player2;

private:
  /**
   * Call the program instead of selecting the movement by mouse.
   */
  int call_player(string program);
public:
  Game(void);
  unsigned board_sizex() {
    return board->sizex();
  }
  unsigned board_sizey() {
    return board->sizey();
  }
  void draw(sf::RenderWindow &windows) {
    board->draw(windows, state->get_values());
  }
  void action(int posx, int posy);
  void press_key(void);
  bool setIntelligentPlayer1(string prog1);
  bool setIntelligentPlayer2(string prog2);
  ~Game();
};

#endif /* GAME_H */
