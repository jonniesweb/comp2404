#include <iostream>
using namespace std;
#include <string>

#include "Chicken.h"


Chicken::Chicken(string n)
    : Bird(n) 
{ 
  initMoves();
}

Chicken::~Chicken() { }

void Chicken::initMoves()
{
  moves[0] = "waddle";
  moves[1] = "strut";
  moves[2] = "flap wings";
  moves[3] = "lay eggs";
  numMoves = 4;
}

