/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include "List.h"
#include "Movie.h"

typedef enum UpdateType { DB_ADD, DB_DELETE } UpdateType;

class Storage {
public:
	Storage();
	virtual ~Storage();

	void retrieve(List<Movie*>*);
	void update(UpdateType, List<Movie*>*);

private:
	List<Movie*>* list;
};

#endif /* STORAGE_H_ */
