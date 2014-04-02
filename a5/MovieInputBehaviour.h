/*
 * MovieInputBehaviour.h
 *
 *  Created on: Apr 1, 2014
 *      Author: jon
 */

#ifndef MOVIEINPUTBEHAVIOUR_H_
#define MOVIEINPUTBEHAVIOUR_H_

#include <vector>

#include "InputBehaviour.h"

class MovieInputBehaviour: public InputBehaviour {
public:
	MovieInputBehaviour();
	virtual ~MovieInputBehaviour();

	void getMediaData(vector<void*>& values);

};

#endif /* MOVIEINPUTBEHAVIOUR_H_ */
