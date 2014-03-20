/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include <string>

#include "Defines.h"
//#include "Movie.h"
#include "MovieList.h"
#include "Serializer.h"


class Storage {
public:
	Storage();
	virtual ~Storage();

	void handleRequest(string&, string&);

private:
	MovieList list;
	Serializer serializer;

	void retrieve(MovieList&);
	void update(UpdateType, MovieList&);
};

#endif /* STORAGE_H_ */
