#include "iostream"
#include <SFML/Graphics.hpp>
#include "Tank.h"

int main()
{

  sf::RenderWindow *window;
  window=new sf::RenderWindow(sf::VideoMode(800, 600), "Tankie!");
  window->setFramerateLimit(20);

  //Sprite for displaying Background Image
  sf::Sprite *bgsprite;
  sf::Texture bgtex;
  if(!bgtex.loadFromFile("Assets/tankmap1.png"))
  {
    std::cout<<"\nError loading background";
  }
  bgsprite=new sf::Sprite();
  bgsprite->setTexture(bgtex);
  bgsprite->setTextureRect(sf::IntRect(0,0,800,600));

  //Creating new hero tank
  Tank *herotank=new Tank(400,500,true);
	
  while (window->isOpen())
  {
    sf::Event event;
    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window->close();

    }
		
    herotank->handle_input();
    herotank->update();

    //Displaying all on the window
    window->clear();
    window->draw(*bgsprite);
    herotank->display(window);
    window->display();

  }

  return 0;
}

