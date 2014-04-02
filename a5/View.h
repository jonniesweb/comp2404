/*
 * View.h
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 */

#ifndef VIEW_H_
#define VIEW_H_

//#include <string>

#include "List.h"
#include "Media.h"
#include "Movie.h"

using std::string;

class View {
public:
	View();
	~View();
	int getMediaType();
//	const void listMovies(List<Media>&);
//	const void listMoviesReverse(List<Media>&);
	int getMenuChoice();
	void displayMessage(const string&);
	void getMovies(List<Media>&);
	string deleteMovie();
	Genre getGenre();

	static string getString();
	static int getInt();

private:

	Movie& getMovie();
	void displayMenu();
	string genreToString(Genre);
};

#endif /* VIEW_H_ */
