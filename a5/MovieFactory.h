/*
 * MovieFactory.h
 *
 *  Created on: Apr 2, 2014
 *      Author: jon
 */

#ifndef MOVIEFACTORY_H_
#define MOVIEFACTORY_H_

#include <vector>

#include "MediaFactory.h"
#include "Media.h"

class MovieFactory: public MediaFactory {
public:
	MovieFactory();
	virtual ~MovieFactory();

	void createData(vector<void*>& values, Media** newMedia);
};

#endif /* MOVIEFACTORY_H_ */
