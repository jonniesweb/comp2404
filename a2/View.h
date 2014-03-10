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
#include "DynArray.h"

using std::string;

class View {
public:
	View();
	~View();
	void listMovies(DynArray*);
	int getMenuChoice();
	void displayMessage(string);
	void getMovies(DynArray*);
	string deleteMovie();
	Genre getGenre();

private:

	Movie* getMovie();
	string getString();
	int getInt();
	void displayMenu();
	string genreToString(Genre);
};

#endif /* VIEW_H_ */
