/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include "MovieList.h"
#include "Movie.h"

typedef enum UpdateType { DB_ADD, DB_DELETE } UpdateType;

class Storage {
public:
	Storage();
	virtual ~Storage();

	void handleRequest(string&, string&);
	void retrieve(MovieList&);
	void update(UpdateType, MovieList&);

private:
	MovieList list;

};

#endif /* STORAGE_H_ */
