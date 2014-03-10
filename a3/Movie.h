/*
 * Movie.h
 *
 *  Created on: Jan 30, 2014
 *      Author: jon
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>

typedef enum Genre { COMEDY, ACTION, HORROR, DRAMA, SF, ADVENTURE, WESTERN, UNKNOWN } Genre;

using std::string;

class Movie {
public:
	Movie(string, int, Genre);
	~Movie();
	Movie(Movie&);

	string& getTitle();
	int getYear();
	Genre getGenre();
	bool operator==(const Movie& movie);

private:
	string title;
	int year;
	Genre genre;


};

#endif /* MOVIE_H_ */
