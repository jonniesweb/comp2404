/*
 * Book.h
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "Media.h"

class Book: public Media {
public:
	Book(string title, int year, string author, string isbn);
	virtual ~Book();
	string& getAuthor();
	string& getIsbn();

private:
	string author;
	string isbn;
};

#endif /* BOOK_H_ */
