/*
 * Movie.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: jon
 *
 * Movie class represents a movie by storing title, year and genre.
 */

#include "Movie.h"
#include "Media.h"
#include <sstream>

using std::stringstream;
using std::endl;


//#include <iostream>
//#include <string>

using std::string;

/**
 * Creates a Movie object with the given title, year and genre
 * @param title
 * @param year
 * @param genre
 */
Movie::Movie(const string& title, const int year, const Genre genre) :
		Media(title, year), genre(genre) {
}

Movie::~Movie() {
}

Movie::Movie(const Movie& movie) : Media(movie.title, movie.year), genre(movie.genre) {
//	std::cout << "Movie " << title << " has been copied" << std::endl;
}

/**
 * get movie genre
 * @return
 */
Genre Movie::getGenre() const {

	return genre;
}

bool Movie::operator==(const Movie& movie) {
	return (movie.genre == genre && movie.title == title && movie.year == year);
}

void Movie::print(ostream& ss) const {
	ss << "Title: ";
	ss << title;
	ss << endl;
	ss << "Year:  ";
	ss << year;
	ss << endl;

	Genre genre = this->genre;
	string strGenre;
	switch (genre) {
		case COMEDY:
			strGenre = "Comedy";
			break;

		case ACTION:
			strGenre = "Action";
			break;

		case HORROR:
			strGenre = "Horror";
			break;

		case DRAMA:
			strGenre = "Drama";
			break;

		case SF:
			strGenre = "Science-Fiction";
			break;

		case ADVENTURE:
			strGenre = "Adventure";
			break;

		case WESTERN:
			strGenre = "Western";
			break;

		case UNKNOWN: // fallthrough
		default:
			strGenre = "Unknown";
			break;
		}

	ss << "Genre: ";
	ss << strGenre;
	ss << endl;

}
