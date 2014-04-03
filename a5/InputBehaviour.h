/*
 * InputBehaviour.h
 *
 *  Created on: Apr 1, 2014
 *      Author: jon
 */

#ifndef INPUTBEHAVIOUR_H_
#define INPUTBEHAVIOUR_H_

#include <vector>

using std::vector;

class InputBehaviour {
public:
	virtual ~InputBehaviour() {};
	virtual void getMediaData(vector<void*>&) = 0;

};

#endif /* INPUTBEHAVIOUR_H_ */
