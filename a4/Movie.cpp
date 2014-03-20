/*
 * Movie.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: jon
 *
 * Movie class represents a movie by storing title, year and genre.
 */

#include "Movie.h"
#include <iostream>
#include <string>

using std::string;

/**
 * Creates a Movie object with the given title, year and genre
 * @param title
 * @param year
 * @param genre
 */
Movie::Movie(string title, int year, Genre genre) {
	this->title = title;
	this->year = year;
	this->genre = genre;

}

Movie::~Movie() {

}

Movie::Movie(const Movie& movie) :
		title(movie.title), year(movie.year), genre(movie.genre) {
//	std::cout << "Movie " << title << " has been copied" << std::endl;
}

/**
 * Get movie title
 * @return
 */
string& Movie::getTitle() {

	return title;
}

/**
 * Get movie year
 * @return
 */
int Movie::getYear() {

	return year;
}

/**
 * get movie genre
 * @return
 */
Genre Movie::getGenre() {

	return genre;
}

bool Movie::operator==(const Movie& movie) {
	return (movie.genre == genre && movie.title == title
			&& movie.year == movie.year);
}

ostream& operator<<(ostream& os, Movie& movie) {
	os << "title: " << movie.getTitle() << " year: " << movie.getYear() << " genre: " << movie.getGenre();
	return os;
}
