#ifndef CAT_H
#define CAT_H

#include "defs.h"
#include "Animal.h"

class Cat : public Animal
{
  public:
    Cat(string="");
    ~Cat();
  private:
    void   initMoves();
};

#endif
