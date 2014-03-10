#include <iostream>
using namespace std;
#include <string>

#include "Cat.h"


Cat::Cat(string n)
    : Animal(n) 
{ 
  initMoves();
}

Cat::~Cat() { }

void Cat::initMoves()
{
  moves[0] = "sleep";
  moves[1] = "pounce";
  moves[2] = "eat";
  moves[3] = "chase mice";
  moves[4] = "torture rodents";
  numMoves = 5;
}

