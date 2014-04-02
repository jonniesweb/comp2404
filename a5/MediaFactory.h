/*
 * MediaFactory.h
 *
 *  Created on: Apr 2, 2014
 *      Author: jon
 */

#ifndef MEDIAFACTORY_H_
#define MEDIAFACTORY_H_

#include <vector>
#include "Media.h"

using std::vector;

class MediaFactory {
	virtual void createData(vector<void*>& values, Media** newMedia) = 0;
};



#endif /* MEDIAFACTORY_H_ */
