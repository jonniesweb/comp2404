/*
 * Book.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#include "Book.h"

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
