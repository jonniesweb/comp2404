#include <iostream>
using namespace std;
#include <string>

#include "Pig.h"


Pig::Pig(string n)
    : Animal(n) 
{ 
  initMoves();
}

Pig::~Pig() { }

void Pig::initMoves()
{
  moves[0] = "sleep";
  moves[1] = "roll in mud";
  moves[2] = "eat";
  numMoves = 3;
}

