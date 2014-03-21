/*
 * Server.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 *
 * Server class. Stands in between the Controller and the Storage class. Will
 * be added onto for future assignments.
 */

#include "Server.h"

#include <string>

#include "Defines.h"
#include <cstdlib>

using std::cout;

Server::Server(const string host, int port) {
	bool result = net.open(host, port);

	if (result) {
//		cout << "connected to server\n";
	} else {
		cout << "failed to connect to server\n";
		exit(EXIT_FAILURE);
	}
}

Server::~Server() {
	net.closeConn();
}

/**
 * Get all movies from Storage object
 * @param movies
 */
void Server::getAllMovies(MovieList& movies) {
	UpdateType action = DB_RETRIEVE;
	string serial;
	serializer.serialize(movies, action, serial);

	net.transmit(serial);

	if (!net.good()) {
		std::cerr << "Bad things happened in the magic code when transmitting movies to get\n";
	}

	string response;
	net.receive(response);

	if (!net.good()) {
		std::cerr << "Bad things happened in the magic code when receiving movies\n";
	}

	serializer.deserialize(response, action, movies);


}

/**
 * Add a DynArray of movies to the Storage object
 * @param movies
 */
void Server::addMovies(MovieList& movies) {
	UpdateType action = DB_ADD;
	string serial;
	serializer.serialize(movies, action, serial);

	net.transmit(serial);
	if (!net.good()) {
		std::cerr << "Bad things happened in the magic code when transmitting movies to add\n";
	}

}

/**
 * Remove a DynArray of movies from the Storage object
 * @param movies
 */
void Server::removeMovies(MovieList& movies) {
	UpdateType action = DB_DELETE;
	string serial;

	serializer.serialize(movies, action, serial);

	net.transmit(serial);
	if (!net.good()) {
		std::cerr << "Bad things happened in the magic code when transmitting movies to remove\n";
	}
}

/**
 * Send a shutdown message to the server to shut it down
 */
void Server::shutDown() {
	MovieList movies;
	UpdateType action = DB_SHUTDOWN;
	string serial;

	serializer.serialize(movies, action, serial);

	net.transmit(serial);

}
