/*
 * Controller.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "DynArray.h"
#include "View.h"
#include "Server.h"

using std::string;

class Controller {
public:
	Controller();
	virtual ~Controller();

private:
	Server masterMovies;
	DynArray localMovies;
	View view;

};

#endif /* CONTROLLER_H_ */
