#include "Tank.h"
#include "math.h"
#include "iostream"

Tank::Tank(void)
{
}

Tank::Tank(int x,int y, bool type)
{
	
  Box.width=Box.height=50;
	
  //loading the texture of tank from assets folder
  if(!tanktex.loadFromFile("Assets/props.png"))
  {
  std::cout<<"\nError loading tank image";
  }
  //creating sprite		
  tanksprite=new sf::Sprite();
  //loading texture into sprite
  tanksprite->setTexture(tanktex);

  if(type==true)//if type==true then its hero tank
  {
    Box.left=x;
    Box.top=y;
    //clipping only the hero tank from the big spritesheet
    tanksprite->setTextureRect(sf::IntRect(0,0,50,50));
  }
  else // for enemy tank if used
  {
    Box.left=rand()%750;
    Box.top=rand()%300;
  	tanksprite->setTextureRect(sf::IntRect(50,0,50,50));
  }

  yVel=0; //x and y vel are 0 initially since tank is not moving
  xVel=0;
  rotate=UP; // by default the tank points up
}
Tank::~Tank(void)
{
}
void Tank::handle_input()
{
	
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    yVel=-VEL;
    rotate=UP; 
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    yVel=+VEL;
    rotate=DOWN;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    xVel=-VEL;
    rotate=LEFT;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    xVel=+VEL;
    rotate=RIGHT;
  }

}
void Tank::update()
{
  Box.top+=yVel; // updating tank’s x and y values
  Box.left+=xVel;
  yVel=0; xVel=0;
}
void Tank::display(sf::RenderWindow *window)
{
  //rotating the sprite according to direction of movement
  if(rotate==UP)
    tanksprite->setRotation(0);
  else if(rotate==DOWN)
    tanksprite->setRotation(180);
  else if(rotate==LEFT)
    tanksprite->setRotation(270);
  else if(rotate==RIGHT)
    tanksprite->setRotation(90);

  tanksprite->setPosition((float)Box.left,(float)Box.top);
  window->draw(*tanksprite); //drawing tank on window

}
void Tank::setPosition(int x,int y)
{
  Box.left=x;
  Box.top=y;
}

