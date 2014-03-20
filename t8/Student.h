#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student(string = "000000000", string = "");
	~Student();
	string getName() const;
	void setName(string);
	void print() const;
	ostream& operator<<(ostream& in);

private:
	const string number;
	string name;
};

#endif
