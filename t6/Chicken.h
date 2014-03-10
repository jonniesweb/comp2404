#ifndef CHICKEN_H
#define CHICKEN_H

#include "defs.h"
#include "Bird.h"

class Chicken : public Bird
{
  public:
    Chicken(string="");
    ~Chicken();
  private:
    void   initMoves();
};

#endif
