/*
 * Controller.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "List.h"
#include "Server.h"
#include "View.h"

using std::string;

class Controller {
public:
	Controller();
	virtual ~Controller();

private:
	Server movieStore;
	View view;

};

#endif /* CONTROLLER_H_ */
