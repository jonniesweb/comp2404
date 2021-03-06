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

bool MovieList::add(const Movie& movie) {
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

const int MovieList::getSize() {
	return list.getSize();
}

Movie& MovieList::get(const int index) {
	return list.get(index);
}


MovieList& MovieList::operator=(MovieList& rhs) {

	// clear the list
	int size = list.getSize();
	for (int i = 0; i < size; ++i) {
		remove(0);
	}

	// add all elements to the list
	for (int i = 0; i < rhs.getSize(); ++i) {
		add(rhs.get(i));
	}

	return rhs;

}

MovieList& MovieList::operator+=(const Movie* rhs) {

	add(*rhs);
	return *this;

}

MovieList& MovieList::operator+=(MovieList& rhs) {

	addAll(rhs);
	return *this;

}

MovieList& MovieList::operator+(const Movie* rhs) {

	MovieList movies(*this);
	movies += rhs;
	return movies;

}

MovieList& MovieList::operator+(MovieList& rhs) {

	MovieList movies(*this);
		movies += rhs;
		return movies;

}

MovieList& MovieList::operator-=(const Movie* rhs) {

	remove(*rhs);
	return *this;

}

MovieList& MovieList::operator-=(MovieList& rhs) {

	removeAll(rhs);
	return *this;
}

MovieList& MovieList::operator-(const Movie* rhs) {

	MovieList movies(*this);
	movies -= rhs;
	return movies;
}

MovieList& MovieList::operator-(MovieList& rhs) {

	MovieList movies(*this);
	movies -= rhs;
	return movies;
}



