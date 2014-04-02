/*
 * MovieFactory.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: jon
 */

#include "MovieFactory.h"
#include "Movie.h"

MovieFactory::MovieFactory() {
}

MovieFactory::~MovieFactory() {
}

/**
 * Create a movie out of the values in the vector
 * @param values
 * @param newMedia
 */
void MovieFactory::createData(vector<void*>& values, Media** newMedia) {

	string* title = (string*) values[0];
	int* year = (int*) values[1];
	int* genreInt = (int*) values[2];

	Genre genre;

	switch (*genreInt) {
		case 1:
			genre = COMEDY;
			break;
		case 2:
			genre = DRAMA;
			break;
		case 3:
			genre = ACTION;
			break;
		case 4:
			genre = HORROR;
			break;
		case 5:
			genre = SF;
			break;
		case 6:
			genre = ADVENTURE;
			break;
		case 7:
			genre = WESTERN;
			break;
		default:
			genre = UNKNOWN;
		}

	Movie* movie = new Movie(*title, *year, genre);

	delete title;
	delete year;
	delete genreInt;

	*newMedia = movie;

}
