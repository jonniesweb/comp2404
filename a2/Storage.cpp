/*
 * Storage.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: jon
 *
 * Storage class is a facade for the highly advanced DynArray class. Allows
 * getting, updating and deleting movies.
 */

#include "Storage.h"
#include "DynArray.h"

Storage::Storage() {

}

Storage::~Storage() {
}

/**
 * Get all movies from the DynArray
 * @param movies
 */
void Storage::retrieve(DynArray* movies) {
	for (int i = 0; i < dynArray.getSize(); ++i) {
		movies->addMovie(dynArray.movieList[i]);
	}
}

/**
 * Either add or delete movies from the DynArray of movies depending on the
 * UpdateType enum.
 * @param updateType
 * @param movies
 */
void Storage::update(UpdateType updateType, DynArray* movies) {

	switch (updateType) {
	case DB_ADD:
		for (int i = 0; i < movies->getSize(); ++i) {
			dynArray.addMovie(movies->movieList[i]);
		}

		break;

	case DB_DELETE:
		for (int i = 0; i < movies->getSize(); ++i) {
			dynArray.removeMovie(movies->movieList[i]->getTitle());
		}

		break;
	default:
		break;
	}
}
