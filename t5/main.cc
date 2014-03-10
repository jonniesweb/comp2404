#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>

#include "Student.h"
#include "List.h"

int main()
{
  ifstream infile("stu.txt",ios::in);
  if (!infile) {
    cout<<"could not open file"<<endl;
    exit(1);
  }

  List comp2404, comp2404two;

  cout << endl << "EMPTY LIST: " << endl;
  comp2404.print();

  Student* stuPtr;
  string   name, number;

  while (infile >> number >> name) {
    stuPtr = new Student(number, name);
    comp2404.addFront(stuPtr);
    comp2404two.addAlpha(stuPtr);
  }

  cout << endl << "ADDED TO FRONT: " << endl;
  comp2404.print();

  cout << endl << "ADDED IN ALPHABETICAL ORDER: " << endl;
  comp2404two.print();

  return 0;
}

