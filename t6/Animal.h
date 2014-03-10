#ifndef ANIMAL_H
#define ANIMAL_H

#include "defs.h"


class Animal
{
  public:
    Animal(string="unknown");
    ~Animal();
    string getName()      const;
    string getStatus()    const;
    void   dance();

  protected:
    string moves[MAX_MOVES];
    int    numMoves;

  private:
    string name;
    string status;
    string nextMove() const;
};

#endif
