#include "board.h"

static sf::Color cell_bg(203, 239, 241);

Board::Board(int nrows, int ncols, int size) {
  const int tam = nrows * ncols;
  const int thickness = 2.0;
  int total = 0;
  this->nrows = nrows;
  this->ncols = ncols;
  this->size = size;

  this->current = nullptr;
  // Header
  font.loadFromFile("sansation.ttf");
  this->text = new sf::Text("Init", font);
  this->text->setCharacterSize(30);
  this->header = new sf::RectangleShape(sf::Vector2f(ncols*size, HEADER_SIZE));
  this->header->setFillColor(sf::Color::Black);
  cells = new sf::RectangleShape *[tam];

  for (int x = 0; x < ncols; x++) {
    for (int y = 0; y < nrows; y++) {
      cells[total] = new sf::RectangleShape(
          sf::Vector2f(size - thickness, size - thickness));
      cells[total]->setPosition(x * size+2, y * size+header->getGlobalBounds().height);
      cells[total]->setFillColor(sf::Color::Black);
      cells[total]->setOutlineColor(cell_bg);
      cells[total]->setOutlineThickness(2.0);
      total += 1;
    }
  }
}

void Board::draw(sf::RenderWindow &windows, const int *values) {
  int total = nrows * ncols;

  for (int i = 0; i < total; i++) {
    windows.draw(*cells[i]);
  }

  for (int y = 0; y < nrows; y++) {
    for (int x = 0; x < ncols; x++) {
      int value = values[y*ncols+x];

      if (value != 0) {
        sf::Color color = colors[value-1];
        sf::CircleShape shape(size/2);
        shape.setFillColor(color);
        shape.setPosition(x*size+2, y*size+HEADER_SIZE);
        windows.draw(shape);
      }
    }
  }

  windows.draw(*header);
  windows.draw(*text);
}



void Board::setText(std::string msg) {
  sf::Vector2f pos_text = header->getPosition();
  text->setString(msg);
  pos_text.x += header->getSize().x/2.0 - this->text->getGlobalBounds().width/2;
  pos_text.y += header->getSize().y/2.0 - this->text->getLocalBounds().height + 3;
  this->text->setPosition(pos_text);
}

int Board::getPosX(unsigned posx) {
  if (posx < 2) 
    return -1;
  else
    return (posx-2) / this->size;
}

int Board::getPosY(unsigned posy) {
  if (posy < HEADER_SIZE)
    return -1;
  else
    return (posy-HEADER_SIZE) / this->size;
}

Board::~Board(void) {
  int total = nrows * ncols;

  if (cells != nullptr) {
    for (int i = 0; i < total; i++) {
      delete cells[i];
    }

    delete[] cells;
    cells = nullptr;
  }

  if (header != nullptr) {
    delete header;
    header = nullptr;
  }

  if (text != nullptr) {
    delete text;
    text = nullptr;
  }

}
