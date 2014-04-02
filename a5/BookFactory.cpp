/*
 * BookFactory.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: jon
 */

#include "BookFactory.h"
#include "Book.h"

BookFactory::BookFactory() {
}

BookFactory::~BookFactory() {
}

/**
 * Create a book out of the values in the vector
 * @param values
 * @param newMedia
 */
void BookFactory::createData(vector<void*>& values, Media** newMedia) {

	// fml. terrible design specs
	string* title = (string*) values[0];
	int* year = (int*) values[1];
	string* author = (string*) values[2];
	string* isbn = (string*) values[3];

	Book* book = new Book(*title, *year, *author, *isbn);

	delete title;
	delete year;
	delete author;
	delete isbn;

	*newMedia = book;


}
