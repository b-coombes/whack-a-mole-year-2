
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite bird;
  sf::Texture bird_texture;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Font font;
  sf::Text title_text;
  sf::Text play_text;
  sf::Text quit_text;

  bool in_menu = true;
  bool play_selected = true;

};

#endif // PLATFORMER_GAME_H
