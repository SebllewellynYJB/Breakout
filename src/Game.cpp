#include "Game.h"
#include <iostream>
#include "GameObject.h"
#include "Vector2.h"

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  //Menu information
  in_menu = true;
  //Font information
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  // Menu text information
  title_text.setString("Breakout");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color(255,0,0));
  title_text.setPosition(430,0);

  play.setString("Play");
  play.setFont(font);
  play.setCharacterSize(40);
  play.setFillColor(sf::Color(0, 100, 0));
  play.setPosition(360,200);

  quit.setString("Quit");
  quit.setFont(font);
  quit.setCharacterSize(40);
  quit.setFillColor(sf::Color(100, 0, 0));
  quit.setPosition(560,200);

  menui.setString("Use left and right arrows to navigate menu, press enter to move on");
  menui.setFont(font);
  menui.setCharacterSize(20);
  menui.setFillColor(sf::Color(200,200,200));
  menui.setPosition(10,350);

  quitany.setString("Press Q to quit at any time");
  quitany.setFont(font);
  quitany.setCharacterSize(20);
  quitany.setFillColor(sf::Color(100,0,200));
  quitany.setPosition(10,400);

  instructions.setString("How to play");
  instructions.setFont(font);
  instructions.setCharacterSize(40);
  instructions.setFillColor(sf::Color(200,50,20));
  instructions.setPosition(10,275);

  paddlei.setString("Blue paddle- left to move left,"
                  "right to move right");
  paddlei.setFont(font);
  paddlei.setCharacterSize(20);
  paddlei.setFillColor(sf::Color(0,0,200));
  paddlei.setPosition(10,450);

  // Game objects information
  paddleb.initialiseSprite(paddleb_texture, "Data/Images/paddleBlue.png");
  paddleb.getSprite()->setPosition(440,650);

  ball.initialiseSprite(ball_texture, "Data/Images/ball.png");
  ball.getSprite()->setPosition(500,600);
  ball.getSprite()->setScale(0.3,0.3);

  for (int i = 0; i < no_of_blocksg; i++)
  {
    blocksg[i].initialiseSprite(blocksg_texture , "Data/Images/element_green_rectangle_glossy.png");
    blocksg[i].getSprite()->setPosition(i * blocksg[i].getSprite()->getGlobalBounds().width, 50);
    blocksg[i].getSprite()->setScale(0.875,0.875);
  }
  for (int i = 0; i < no_of_blocksr; i++)
  {
    blocksr[i].initialiseSprite(
      blocksr_texture, "Data/Images/element_red_rectangle_glossy.png");
    blocksr[i].getSprite()->setPosition(i * blocksr[i].getSprite()->getGlobalBounds().width, 100);
    blocksr[i].getSprite()->setScale(0.875, 0.875);
    blocksr[5].setIsvisible(false);
    blocksr[4].setIsvisible(true);
  }
  // Sets ball speed
  ball.setBallSpeed(-100);
  ball.setBallDirection(Vector2{1,1});
    return true;
}

void Game::update(float dt)
{
  // Ball movement every frame
  ball.getSprite()->move(ball.getBallDirection().x * ball.getBallSpeed() * dt ,
                         ball.getBallDirection().y * ball.getBallSpeed() * dt);
  // Code to update visible blocks each frame
  for (int i = 0; i < no_of_blocksg; ++i)
  {
    if (collisionCheck(*ball.getSprite() , *blocksg[i].getSprite()))
    {
      blocksg[i].setIsvisible(false);
    }
  }
  // Code for paddle movement
  paddleb.getSprite()->move(paddleb_direction.x * paddleb.getPaddlebSpeed() * dt,0);
}
void Game::render()
{
  if (in_menu)
  // Text that is rendered to the menu
  {
    window.draw(title_text);
    window.draw(play);
    window.draw(quit);
    window.draw(menui);
    window.draw(quitany);
    window.draw(instructions);
    window.draw(paddlei);
  }
  else
    // Game objects rendered
  {
    window.draw(*paddleb.getSprite());
    window.draw(*ball.getSprite());
    for (int i = 0; i < no_of_blocksg; i++)
    {
      if (blocksg[i].isIsvisible())
      {
        window.draw(*blocksg[i].getSprite());
      }
    }
    for (int i = 0; i < no_of_blocksr; i++)
    {
      if (blocksr[i].isIsvisible())
      {
        window.draw(*blocksr[i].getSprite());
      }
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  // Menu keys for play and quit
  if (
    (event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play.setString("> Play <");
      quit.setString("Quit");
    }
    else
    {
      play.setString("Play");
      quit.setString("> Quit <");
    }
  }
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
  // Key pressed details for paddle movement
  if (event.key.code == sf::Keyboard::Left)
  {
    paddleb_direction.x = -1;
  }
  else if (event.key.code == sf::Keyboard::Right)
  {
    paddleb_direction.x = 1;
  }
  if (event.key.code == sf::Keyboard::Q)
  {
    window.close();
  }
}
void Game::KeyReleased(sf::Event event)
{
  // Key released details for paddle movement
  if ((event.key.code == sf::Keyboard::Left)||
      (event.key.code == sf::Keyboard::Right))
  {
    paddleb_direction.x = 0;
    paddleb_direction.y = 0;
  }
}
bool Game::collisionCheck(sf::Sprite sprite1, sf::Sprite sprite2)
{
  return false;
}