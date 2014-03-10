#include <cstdio>
#include <iostream>
using namespace std;

#include "defs.h"
#include "Bird.h"
#include "Chicken.h"
#include "Cat.h"
#include "Pig.h"


int main()
{
  Animal* barn[MAX_ANIMALS];
  int numAnimals = 0;

  int    num,c;
  string name;

  cout << "How many birds? ";
  cin  >> num; cin.ignore();
  for (int i=0; i<num; i++) {
    cout << "Name " << i+1 << ":  ";
    getline(cin, name);
    barn[numAnimals++] = new Bird(name);
  }

  cout << "How many chickens? ";
  cin  >> num; cin.ignore();
  for (int i=0; i<num; i++) {
    cout << "Name " << i+1 << ":  ";
    getline(cin, name);
    barn[numAnimals++] = new Chicken(name);
  }

  cout << "How many cats? ";
  cin  >> num; cin.ignore();
  for (int i=0; i<num; i++) {
    cout << "Name " << i+1 << ":  ";
    getline(cin, name);
    barn[numAnimals++] = new Cat(name);
  }

  cout << "How many pigs? ";
  cin  >> num; cin.ignore();
  for (int i=0; i<num; i++) {
    cout << "Name " << i+1 << ":  ";
    getline(cin, name);
    barn[numAnimals++] = new Pig(name);
  }

  for (int i=0; i<numAnimals; i++)
    barn[i]->dance();

  for (int i=0; i<numAnimals; i++)
    cout << barn[i]->getName() << endl;

  cout<<endl;

  return 0;
}

