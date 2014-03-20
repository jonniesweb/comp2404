/*
 * Server.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "Storage.h"
#include "MovieList.h"

class Server {
public:
	Server();
	virtual ~Server();

	void getAllMovies(MovieList&);
	void addMovies(MovieList&);
	void removeMovies(MovieList&);

	void shutDown();

private:
	Storage db;
	Serializer serializer;
};

#endif /* SERVER_H_ */
