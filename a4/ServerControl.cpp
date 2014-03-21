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
#include <cstdlib>

#include "Defines.h"

using std::cout;

ServerControl::ServerControl() {

}

ServerControl::~ServerControl() {
	net.closeConn();
}

void ServerControl::launch() {

	bool running = false;
	bool result = net.open(SERVER_PORT);

	goodCheck();

	if (result) {
		cout << "binded to port\n";
		running = true;
	}

	while (running) {

		goodCheck();

		net.wait();

		goodCheck();

		while (net.good()) {
			string input;
			net.receive(input);

			string output;
			storage.handleRequest(input, output);

			if (output.size() > 0) {
				net.transmit(output);

				goodCheck();
			}
		}
	}
}

void ServerControl::goodCheck() {
	if (!net.good()) {
		cout << "Things have gone bad! Exiting...\n";
		exit(EXIT_FAILURE);
	}
}
