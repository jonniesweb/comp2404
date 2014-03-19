/*
 * View.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <string>
#include "Movie.h"
#include "MovieList.h"

using std::string;

class View {
public:
	View();
	~View();
	const void listMovies(MovieList&);
	const void listMoviesReverse(MovieList&);
	int getMenuChoice();
	void displayMessage(const string&);
	void getMovies(MovieList&);
	string deleteMovie();
	Genre getGenre();

private:

	Movie& getMovie();
	string getString();
	int getInt();
	void displayMenu();
	string genreToString(Genre);
};

#endif /* VIEW_H_ */
