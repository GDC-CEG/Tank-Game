#pragma once
#ifndef TANK_H
#define TANK_H

#include <SFML\Graphics.hpp>

//setting velocity as 10
const int VEL=10;

//to know what direction the tank is moving
const int UP=0;
const int DOWN=1;
const int LEFT=2;
const int RIGHT=3;

class Tank
{
public:

  sf::IntRect Box; // box to keep track of x and y of tank
  int xVel,yVel;  // to track x and y velocity of tank ( can be +ve or –ve )

  sf::Sprite *tanksprite; //sprite for displaying tank
  sf::Texture tanktex;  // texture to load tank image

  int rotate;  // to know which direction tank is moving. Can take values UP, DOWN, // LEFT and RIGHT

  Tank(void);
  Tank(int x,int y, bool type);
  ~Tank(void);

  void handle_input();  // to get users input
  void update();   // to update tank’s values
  void display(sf::RenderWindow *window);   // to display tank
  void setPosition(int x,int y);
};

#endif

