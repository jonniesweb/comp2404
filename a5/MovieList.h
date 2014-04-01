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

	/*
	 * Constructor/Destructor
	 */
public:
	MovieList();
	virtual ~MovieList();

	/*
	 * Methods
	 */
public:
	const int getSize();
	Movie& get(int);

private:
	bool add(const Movie&);
	void addAll(MovieList&);
	void remove(const Movie&);
	void removeAll(MovieList&);
	Movie& remove(int);

	/*
	 * Fields
	 */
private:
	List<Movie> list;

	/*
	 * Operators
	 */
public:
	MovieList& operator=(MovieList&);
	MovieList& operator+=(const Movie*);
	MovieList& operator+=(MovieList&);
	MovieList& operator+(const Movie*);
	MovieList& operator+(MovieList&);
	MovieList& operator-=(const Movie*);
	MovieList& operator-=(MovieList&);
	MovieList& operator-(const Movie*);
	MovieList& operator-(MovieList&);


};

#endif /* MOVIELIST_H_ */
