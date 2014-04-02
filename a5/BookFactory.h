/*
 * BookFactory.h
 *
 *  Created on: Apr 2, 2014
 *      Author: jon
 */

#ifndef BOOKFACTORY_H_
#define BOOKFACTORY_H_

#include <vector>

#include "MediaFactory.h"
#include "Media.h"

class BookFactory: public MediaFactory {
public:
	BookFactory();
	virtual ~BookFactory();

	void createData(vector<void*>& values, Media** newMedia);
};

#endif /* BOOKFACTORY_H_ */
