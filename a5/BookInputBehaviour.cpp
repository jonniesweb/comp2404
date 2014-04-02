/*
 * BookInputBehaviour.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: jon
 */

#include "BookInputBehaviour.h"

#include "View.h"

using std::cout;
using std::endl;
using std::string;

BookInputBehaviour::BookInputBehaviour() {
}

BookInputBehaviour::~BookInputBehaviour() {
}

void BookInputBehaviour::getMediaData(vector<void*>& values) {

	// add title, year, author, isbn

	cout << endl;
	cout << "Enter book title:" << endl;
	string* title = new string(View::getString());

	cout << endl;
	cout << "Enter book year:" << endl;
	int* year = new int(View::getInt());

	cout << endl;
	cout << "Enter book author:" << endl;
	string* author = new string(View::getString());

	cout << endl;
	cout << "Enter book ISBN:" << endl;
	string* isbn = new string(View::getString());

	values.push_back(title);
	values.push_back(year);
	values.push_back(author);
	values.push_back(isbn);

}
