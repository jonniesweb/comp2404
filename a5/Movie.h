/*
 * Movie.h
 *
 *  Created on: Jan 30, 2014
 *      Author: jon
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include <string>
#include "Media.h"

typedef enum Genre { COMEDY, ACTION, HORROR, DRAMA, SF, ADVENTURE, WESTERN, UNKNOWN } Genre;

using std::string;
using std::ostream;


class Movie: public Media {

friend ostream& operator<<(ostream&, Movie&);

public:
	Movie(const string&, const int, const Genre);
	~Movie();
	Movie(const Movie&);

	Genre getGenre() const;
	bool operator==(const Movie& movie);

private:
	Genre genre;


};

#endif /* MOVIE_H_ */
