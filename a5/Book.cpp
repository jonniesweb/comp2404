/*
 * Book.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#include "Book.h"
#include <sstream>

using std::stringstream;
using std::endl;

Book::Book(string title, int year, string author, string isbn) :
		Media(title, year), author(author), isbn(isbn) {

}

Book::~Book() {
}

string& Book::getAuthor() {
	return author;
}

string& Book::getIsbn() {
	return isbn;
}

void Book::print(ostream& os) const {
	os << "Title:  ";
	os << title;
	os << endl;
	os << "Year:   ";
	os << year;
	os << endl;
	os << "Author: ";
	os << author;
	os << endl;
	os << "ISBN:   ";
	os << isbn;
	os << endl;

}
