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

Server::Server() {
}

Server::~Server() {
}

/**
 * Get all movies from Storage object
 * @param movies
 */
void Server::getAllMovies(MovieList& movies) {
	db.retrieve(movies);
}

/**
 * Add a DynArray of movies to the Storage object
 * @param movies
 */
void Server::addMovies(MovieList& movies) {
	db.update(DB_ADD, movies);
}

/**
 * Remove a DynArray of movies from the Storage object
 * @param movies
 */
void Server::removeMovies(MovieList& movies) {
	db.update(DB_DELETE, movies);
}
