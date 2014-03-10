/*
 * MovieList.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: jon
 */

#include "MovieList.h"

MovieList::MovieList() {

}

MovieList::~MovieList() {

}

bool MovieList::add(Movie& movie) {
	return list.add(movie);

}

void MovieList::addAll(MovieList& movies) {
	for (int i = 0; i < movies.getSize(); ++i) {
		add(movies.get(i));
	}
}

Movie& MovieList::remove(int index) {
	return list.remove(index);
}

void MovieList::remove(const Movie& movie) {
	list.remove(movie);
}

void MovieList::removeAll(MovieList& movies) {
	for (int i = 0; i < movies.getSize(); ++i) {
			remove(movies.get(i));
		}
}

int MovieList::getSize() {
	return list.getSize();
}

Movie& MovieList::get(int index) {
	return list.get(index);
}

Movie& MovieList::set(int index, Movie& newMovie) {
	return list.set(index, newMovie);
}
