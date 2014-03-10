#include <iostream>
using namespace std;
#include <string>

#include "Bird.h"


Bird::Bird(string n)
    : Animal(n) 
{ 
  initMoves();
}

Bird::~Bird() { }

void Bird::initMoves()
{
  moves[0] = "fly";
  moves[1] = "flap wings";
  moves[2] = "lay eggs";
  numMoves = 3;
}

