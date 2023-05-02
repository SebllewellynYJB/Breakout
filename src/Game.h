
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "GameObject.h"
#include <SFML/Audio.hpp>

class Game
{
 public:
  // Functions
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void KeyReleased(sf::Event event);
  bool collisionCheck(sf::Sprite sprite1 , sf::Sprite sprite2);
  // Game objects
  GameObject paddleb;
  sf::Texture paddleb_texture;
  GameObject ball;
  sf::Texture ball_texture;
  GameObject blocksg[17];
  sf::Texture blocksg_texture;
  const int no_of_blocksg = 17;
  GameObject blocksr[17];
  sf::Texture blocksr_texture;
  const int no_of_blocksr = 17;
  // Vector details
  Vector2 paddleb_direction = {0,0};
  bool reverse = reverse;
 private:
  sf::Sprite sprite;
  //void addTexture(sf::Texture ,sf::Color color);
  // Menu details
  sf::RenderWindow& window;
  sf::Font font;
  sf::Text title_text;
  bool play_selected = true;
  bool in_menu;
  sf::Text play;
  sf::Text quit;
  sf::Text quitany;
  sf::Text instructions;
  sf::Text paddlei;
  sf::Text menui;
  sf::Text score;
  sf::Text timer;
};

#endif // BREAKOUT_GAME_H
