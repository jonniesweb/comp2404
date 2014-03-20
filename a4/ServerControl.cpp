/*
 * ServerControl.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: jon
 */

#include "ServerControl.h"
#include "Connection.h"

#include <iostream>
#include <string>

#define SERVER_PORT 60002

ServerControl::ServerControl() {

}

ServerControl::~ServerControl() {
}

void ServerControl::launch() {

	bool running = false;
	bool result = net.open(SERVER_PORT);

	std::cout << result;

	if (result) {
		running = true;
	}

	while (running) {

		std::cout << net.wait();
		string input;
		net.receive(input);

		std::cout << input;
	}
}
