/*
 * Storage.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 *
 * Storage class is a facade for the highly advanced List class. Allows
 * getting, updating and deleting movies.
 */

#include "Storage.h"

#include <iostream>
//#include <string>

#include "Movie.h"
#include <cstdlib>
//#include "MovieList.h"
//#include "Serializer.h"

Storage::Storage() {
}

Storage::~Storage() {
//	for (int i = 0; i < list.getSize(); ++i) {
//		delete &list.get(i);
//	}
}

void Storage::handleRequest(string& request, string& reply) {

	UpdateType action;
	UpdateType ack = DB_ACK;
	MovieList movies;

	serializer.deserialize(request, action, movies);

	switch (action) {
	case DB_ADD:
	case DB_DELETE:
		update(action, movies);
		break;
	case DB_RETRIEVE:
		retrieve(movies);

		serializer.serialize(movies, ack, reply);

		break;
	case DB_SHUTDOWN:
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}

}

/**
 * Get all movies from the List
 * @param movies
 */
void Storage::retrieve(MovieList& movies) {
	movies += list;
//	std::cout << "Movies retrieved from storage\n";
}

/**
 * Either add or delete movies from the List of movies depending on the
 * UpdateType enum.
 * @param updateType
 * @param movies
 */
void Storage::update(UpdateType updateType, MovieList& movies) {

	switch (updateType) {
	case DB_ADD:
		list += movies;

		break;

	case DB_DELETE:
		list -= movies;

		break;
	default:
		break;
	}
}

