/*
 * Server.h
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "MovieList.h"
#include "Connection.h"
#include "Serializer.h"

class Server {
public:
	Server(const string, int);
	virtual ~Server();

	void getAllMovies(MovieList&);
	void addMovies(MovieList&);
	void removeMovies(MovieList&);

	void shutDown();

private:
	Serializer serializer;
	ClientConnection net;
};

#endif /* SERVER_H_ */
