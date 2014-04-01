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

Storage::Storage() {
}

Storage::~Storage() {
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

