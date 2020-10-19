#include <SFML/Graphics.hpp>
#include <string>

class Board {
  sf::RectangleShape *header;
  sf::RectangleShape **cells;
  sf::Text *text;
  sf::Font font;
  int nrows, ncols;
  int size;
  sf::RectangleShape *current;
  const sf::Color colors[2] = {sf::Color::Green, sf::Color::Yellow};

public:
  const unsigned HEADER_SIZE = 60;
  Board(int nrows, int ncols, int size);
  void draw(sf::RenderWindow &windows,  const int *values);

  unsigned sizex(void) {
    return 6+ncols*size;
  }
  unsigned sizey(void) {
    return nrows*size+HEADER_SIZE;
  }

  int getPosX(unsigned posx);
  int getPosY(unsigned posy);
  void setText(std::string text);
  ~Board(void);
};
