/*
 * ServerControl.h
 *
 *  Created on: Mar 20, 2014
 *      Author: jon
 */

#ifndef SERVERCONTROL_H_
#define SERVERCONTROL_H_

#include "Connection.h"
#include "Storage.h"

class ServerControl {
public:
	ServerControl();
	virtual ~ServerControl();

	void launch();

private:
	void goodCheck();

	ServerConnection net;
	Storage storage;
};

#endif /* SERVERCONTROL_H_ */
