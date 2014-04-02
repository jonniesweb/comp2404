/*
 * MovieInputBehaviour.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: jon
 */

#include "MovieInputBehaviour.h"

#include <iostream>
//#include <string>

#include "View.h"

using std::string;
using std::cout;
using std::endl;


MovieInputBehaviour::MovieInputBehaviour() {
}

MovieInputBehaviour::~MovieInputBehaviour() {
}

void MovieInputBehaviour::getMediaData(vector<void*>& values) {
	// add title year and genre

	cout << endl;
	cout << "Enter movie title:" << endl;
	string* title = new string(View::getString());

	cout << endl;
	cout << "Enter movie year:" << endl;
	int* year = new int(View::getInt());

	cout << endl;
	cout << "Please specify a genre:" << endl;
	cout << "(1) Comedy" << endl;
	cout << "(2) Drama" << endl;
	cout << "(3) Action" << endl;
	cout << "(4) Horror" << endl;
	cout << "(5) Science-Fiction" << endl;
	cout << "(6) Adventure" << endl;
	cout << "(7) Western" << endl;
	int* genre = new int(View::getInt());


	values.push_back(title);
	values.push_back(year);
	values.push_back(genre);

}
