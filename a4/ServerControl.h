/*
 * ServerControl.h
 *
 *  Created on: Mar 20, 2014
 *      Author: jon
 */

#ifndef SERVERCONTROL_H_
#define SERVERCONTROL_H_

#include "Connection.h"

class ServerControl {
public:
	ServerControl();
	virtual ~ServerControl();

	void launch();

private:
	ServerConnection net;
};

#endif /* SERVERCONTROL_H_ */
