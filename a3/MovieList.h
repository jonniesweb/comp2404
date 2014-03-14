/*
 * MovieList.h
 *
 *  Created on: Mar 5, 2014
 *      Author: jon
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_

#include "List.h"
#include "Movie.h"

class MovieList {
public:
	MovieList();
	virtual ~MovieList();

	bool add(Movie&);
	void addAll(MovieList&);
	Movie& remove(int);
	void remove(const Movie&);
	void removeAll(MovieList&);
	int getSize();
	Movie& get(int);
	Movie& set(const int, const Movie&);


private:
	List<Movie> list;


};

#endif /* MOVIELIST_H_ */
