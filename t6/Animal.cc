#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

#include "Animal.h"
#include "Random.h"


Animal::Animal(string n)
    : name(n), status("idle") { }

Animal::~Animal() { }

string Animal::getName()   const { return name; }

string Animal::getStatus() const { return status; }

void   Animal::dance() 
{
  status = nextMove();
  cout << endl << setw(15) << name << " is dancing: " << status << endl;
}

string Animal::nextMove() const
{
  int r = Random::Instance()->NextInt(numMoves);

  return moves[r];
}

