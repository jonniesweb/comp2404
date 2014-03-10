/*
 * DynArray.cpp
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 *
 * Dynamic array implementation. Movies are dynamically stored in this array.
 */

#include "DynArray.h"

#include <string>


using std::string;

DynArray::DynArray() {
	size = 0;
	movieList = new Movie*[1];

}

DynArray::~DynArray() {
	delete[] movieList;
}

/**
 * Add a movie to the DynArray
 * @param movie
 */
void DynArray::addMovie(Movie* movie) {

	++size;

	// grow array
	Movie** newList = new Movie*[size];
	for (int i = 0; i < size - 1; ++i) {
		newList[i] = movieList[i];
	}

	delete[] movieList;
	movieList = newList;

	// add movie to array
	movieList[size - 1] = movie;

}
/**
 * Add an array of movies to the DynArray
 * @param movies
 */
void DynArray::addAllMovies(DynArray* movies) {
	for (int i = 0; i < movies->size; ++i) {
		addMovie(movies->movieList[i]);
	}
}

/**
 * Remove a movie from the DynArray
 * @param movieTitle
 * @return Pointer of removed movie. If not found, return NULL pointer
 */
Movie* DynArray::removeMovie(string movieTitle) {

	int pointer = 0;
	Movie* removedMovie = NULL;
	bool found = false;

	while (pointer < size) {
		// if the movie is found, shift all movie pointers left after the
		// removed movie
		if (found) {
			movieList[pointer - 1] = movieList[pointer];
		}

		// if titles match
		if (!found && movieList[pointer]->getTitle().compare(movieTitle) == 0) {
			removedMovie = movieList[pointer];
			found = true;
		}

		++pointer;
	}

	if (found == false) {
		return NULL;
	}

	// decrease size after everything has shifted over
	--size;

	// shrink array
	Movie** newList = new Movie*[size];
	for (int i = 0; i < size; ++i) {
		newList[i] = movieList[i];
	}

	delete[] movieList;
	movieList = newList;

	return removedMovie;
}

/**
 * Remove multiple movies from the DynArray
 * @param movies
 */
void DynArray::removeAllMovies(DynArray* movies) {
	for (int i = 0; i < movies->size; ++i) {
		removeMovie(movies->movieList[i]->getTitle());
	}
}

/**
 * Get size of this DynArray
 * @return
 */
int DynArray::getSize() {
	return size;
}
