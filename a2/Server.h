/*
 * Server.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include "DynArray.h"
#include "Storage.h"
using std::string;

class Server {
public:
	Server();
	virtual ~Server();

	void getAllMovies(DynArray*);
	void addMovies(DynArray*);
	void removeMovies(DynArray*);

private:
	Storage db;
};

#endif /* SERVER_H_ */
