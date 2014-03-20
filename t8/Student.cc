#include <string>
#include <iostream>

#include "Student.h"

using std::string;
using std::cout;
using std::endl;

Student::Student(string nu, string na) :
		number(nu), name(na) {
}

Student::~Student() {
}

string Student::getName() const {
	return name;
}

void Student::setName(string n) {
	name = n;
}

void Student::print() const {
	cout << "Student:  " << number << "  " << name << endl;
}

ostream& Student::operator<<(ostream& in) {
	in << "Student:  " << number << "  " << name << endl;
	return in;
}
