/*
 * Storage.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef STORAGE_H_
#define STORAGE_H_


#include "Defines.h"
#include "List.h"
#include "Media.h"

class Storage {
public:
	Storage();
	virtual ~Storage();


	void retrieve(List<Media*>&);
	void update(UpdateType, List<Media*>&);
private:
	List<Media*> list;

};

#endif /* STORAGE_H_ */
