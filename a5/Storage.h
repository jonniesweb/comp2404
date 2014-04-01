/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_


#include "Defines.h"
#include "MovieList.h"

class Storage {
public:
	Storage();
	virtual ~Storage();


	void retrieve(MovieList&);
	void update(UpdateType, MovieList&);
private:
	MovieList list;

};

#endif /* STORAGE_H_ */
