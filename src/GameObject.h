#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include "Vector2.h"

class GameObject
{
 public:
  // Game Object functions
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();
  // Functions for paddle and ball Game Objects
  float ball_speed = -100;
  float getBallSpeed() const;
  void setBallSpeed(float ballSpeed);
  float paddleb_speed = 200;
  float getPaddlebSpeed() const;
  void setPaddlebSpeed(float paddlebSpeed);
  Vector2 ball_direction = {0,1};
  const Vector2& getBallDirection() const;
  void setBallDirection(const Vector2& ballDirection);

 private:
  sf::Sprite* sprite = nullptr;
  // Visibility details
  bool isvisible = true;

 public:
  bool isIsvisible(bool b) const;
  void setIsvisible(bool isvisible);
  bool isIsvisible() const;
};

#endif // SPACEINVADERS_GAMEOBJECT_H