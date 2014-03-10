#ifndef PIG_H
#define PIG_H

#include "defs.h"
#include "Animal.h"

class Pig : public Animal
{
  public:
    Pig(string="");
    ~Pig();
  private:
    void   initMoves();
};

#endif
