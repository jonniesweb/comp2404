#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>

#include "Student.h"
#include "List.h"

int main() {
	List list1, list2;
	Student* stuPtr;
	string name, number;

	ifstream infile("stu.txt", ios::in);
	if (!infile) {
		cout << "could not open file" << endl;
		exit(1);
	}

	while (infile >> number >> name) {
		stuPtr = new Student(number, name);
		list1.addFront(stuPtr);
		list2.addAlpha(stuPtr);
	}

	cout << "ADD FRONT FORWARD" << endl;
	list1.print();
	cout << "ADD FRONT BACKWARD" << endl;
	list1.printBack();
	cout << "ADD ALPHA FORWARD" << endl;
	list2.print();
	;
	cout << "ADD ALPHA BACKWARD" << endl;
	list2.printBack();
	;

	cout << "Test equality of same object, should be TRUE" << endl;
	List& list3 = list2;
	cout << (list3 == list2 ? "True" : "False") << endl;

	cout << "Test equality of different objects, should be FALSE" << endl;
	cout << (list2 == list1 ? "True" : "False") << endl;

	cout << "Test inequality of same object, should be FALSE" << endl;
	cout << (list3 != list2 ? "True" : "False") << endl;

	cout << "Test inequality of different objects, should be TRUE" << endl;
	cout << (list2 != list1 ? "True" : "False") << endl;

	cout << "Test array subscript operator. Should return HAROLD" << endl;
	cout << list1[0]->getName() << endl;



	list1.cleanupData();

}

