#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>

using namespace std;

class State {
  vector<int> values;
  const int MAX_WINNER=4;
  int nrows, ncols;
  int player;
  int winner;

  void check_winner(int posx, int posy);
  void count_player(int &cont, int value);

public:
  int get_ncols() { return ncols; }
  int get_nrows() { return nrows; }
  State(string filename);
  State(int nrows, int ncols);
  bool save(string filename);
  State &operator=(const State &newstate);
  //NUEVO ESTADO PARA USARLO RECURSIVO
  State move(int colx);
  const int *get_values() {
    return &values[0];
  }

  int current_player() {
    return player;
  }
  //SABER SI ALGUIEN HA GANADO
  bool has_winner(void);
  //DEVUELVE EL GANADOR
  int get_winner();
};


#endif /* STATE_H */
