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
#include "List.h"
#include "Movie.h"
#include <iostream>

Storage::Storage() {
	list = new List<Movie*>;
}

Storage::~Storage() {
	for (int i = 0; i < list->getSize(); ++i) {
		std::cout << (*list->get(i))->getTitle();
		delete list->get(i);
	}
	delete list;
}

/**
 * Get all movies from the List
 * @param movies
 */
void Storage::retrieve(List<Movie*>* movies) {
	movies->addAll(list);
}

/**
 * Either add or delete movies from the List of movies depending on the
 * UpdateType enum.
 * @param updateType
 * @param movies
 */
void Storage::update(UpdateType updateType, List<Movie*>* movies) {

	switch (updateType) {
	case DB_ADD:
		list->addAll(movies);

		break;

	case DB_DELETE:
		list->removeAll(movies);

		break;
	default:
		break;
	}
}
