/*
 * Server.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include "Storage.h"
using std::string;

class Server {
public:
	Server();
	virtual ~Server();

	void getAllMovies(List<Movie*>*);
	void addMovies(List<Movie*>*);
	void removeMovies(List<Movie*>*);

private:
	Storage db;
};

#endif /* SERVER_H_ */
