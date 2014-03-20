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
#include "List.h"
#include "Serializer.h"
#include "Defines.h"

Server::Server() {
}

Server::~Server() {
}

/**
 * Get all movies from Storage object
 * @param movies
 */
void Server::getAllMovies(MovieList& movies) {
//	db.retrieve(movies);
	UpdateType action = DB_RETRIEVE;
	string serial;
	serializer.serialize(movies, action, serial);

	string response;
	db.handleRequest(serial, response);
	serializer.deserialize(response, action, movies);
}

/**
 * Add a DynArray of movies to the Storage object
 * @param movies
 */
void Server::addMovies(MovieList& movies) {
//	db.update(DB_ADD, movies);
	UpdateType action = DB_ADD;
	string serial;
	serializer.serialize(movies, action, serial);

	string unused;
	db.handleRequest(serial, unused);

}

/**
 * Remove a DynArray of movies from the Storage object
 * @param movies
 */
void Server::removeMovies(MovieList& movies) {
//	db.update(DB_DELETE, movies);
	UpdateType action = DB_DELETE;
	string serial;

	serializer.serialize(movies, action, serial);

	string unused;
	db.handleRequest(serial, unused);
}
