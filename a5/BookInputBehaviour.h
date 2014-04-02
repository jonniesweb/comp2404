/*
 * BookInputBehaviour.h
 *
 *  Created on: Apr 1, 2014
 *      Author: jon
 */

#ifndef BOOKINPUTBEHAVIOUR_H_
#define BOOKINPUTBEHAVIOUR_H_

#include "InputBehaviour.h"

class BookInputBehaviour: public InputBehaviour {
public:
	BookInputBehaviour();
	virtual ~BookInputBehaviour();

	void getMediaData(vector<void*>&);
};

#endif /* BOOKINPUTBEHAVIOUR_H_ */
