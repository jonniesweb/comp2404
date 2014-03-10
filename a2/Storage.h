/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include "DynArray.h"

typedef enum UpdateType { DB_ADD, DB_DELETE } UpdateType;

class Storage {
public:
	Storage();
	virtual ~Storage();

	void retrieve(DynArray*);
	void update(UpdateType, DynArray*);

private:
	DynArray dynArray;
};

#endif /* STORAGE_H_ */
