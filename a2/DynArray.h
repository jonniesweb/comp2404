/*
 * DynArray.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <string>

#define MAX_SIZE 32

#include "Movie.h"

class DynArray {
	friend class Controller;
	friend class Storage;
	friend class Server;
	friend class View;
public:
	DynArray();
	virtual ~DynArray();

	void addMovie(Movie*);
	void addAllMovies(DynArray*);
	Movie* removeMovie(string);
	void removeAllMovies(DynArray*);

	int getSize();

private:
	int size;
	Movie** movieList;
};

#endif /* DYNARRAY_H_ */
