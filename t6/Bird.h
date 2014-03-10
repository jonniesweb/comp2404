#ifndef BIRD_H
#define BIRD_H

#include "defs.h"
#include "Animal.h"

class Bird : public Animal
{
  public:
    Bird(string="");
    ~Bird();
  private:
    void   initMoves();
};

#endif
