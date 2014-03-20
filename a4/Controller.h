/*
 * Controller.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "View.h"
#include "Server.h"
#include "List.h"

using std::string;

class Controller {
public:
	Controller();
	virtual ~Controller();

private:
	Server movieStore; // server copy
	View view;

};

#endif /* CONTROLLER_H_ */
