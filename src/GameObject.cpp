#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  delete sprite;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout  <<"texture did not load";
  }
  sprite->setTexture(texture);
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}
// Visibility information
bool GameObject::isIsvisible() const
{
  return isvisible;
}
void GameObject::setIsvisible(bool isvisible)
{
  GameObject::isvisible = isvisible;
}
float GameObject::getPaddlebSpeed() const
{
  return paddleb_speed;
}
void GameObject::setPaddlebSpeed(float paddlebSpeed)
{
  paddleb_speed = paddlebSpeed;
}
float GameObject::getBallSpeed() const
{
  return ball_speed;
}
void GameObject::setBallSpeed(float ballSpeed)
{
  ball_speed = ballSpeed;
}
const Vector2& GameObject::getBallDirection() const
{
  return ball_direction;
}
void GameObject::setBallDirection(const Vector2& ballDirection)
{
  ball_direction = ballDirection;
}
