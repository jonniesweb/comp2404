/*
 * Controller.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Storage.h"
#include "View.h"


class Controller {
public:
	Controller();
	virtual ~Controller();

private:
	Storage storage;
	View view;

};

#endif /* CONTROLLER_H_ */
