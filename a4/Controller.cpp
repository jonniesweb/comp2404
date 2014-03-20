/*
 * Controller.cpp
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 *
 * Controller class for the Movie Database Program. Uses View class for all
 * user I/O and uses Server class for all future data storage. Keeps a local
 * copy of DynArray so that in the future a local copy will be cached instead
 * of having to query the Server every time an action is performed.
 */

#include "Controller.h"

//#include <cstdlib>
#include <iostream>
#include <string>

#include "Movie.h"
#include "MovieList.h"
#include "Serializer.h"
#include "Storage.h"

using std::string;
using std::cout;
using std::endl;

/**
 * Constructor handles program flow. Gets user menu choice then acts on that.
 */
Controller::Controller() {

#if 1

	bool running = true;
	int menuChoice = -1;

	do {
		menuChoice = view.getMenuChoice();

		if (menuChoice == 1) { // add movies

			MovieList newMovies;
			view.getMovies(newMovies);

			movieStore.addMovies(newMovies);

		} else if (menuChoice == 2) { // delete movie

			MovieList removedMovies;
			string movieTitle = view.deleteMovie();

			MovieList movieList;
			movieStore.getAllMovies(movieList);

			for (int i = 0; i < movieList.getSize(); ++i) {
				if (movieList.get(i).getTitle().compare(movieTitle) == 0) {
					removedMovies.add(movieList.get(i));
				}
			}

			movieStore.removeMovies(removedMovies);

		} else if (menuChoice == 3) { // list all movies

			MovieList allMovies;
			movieStore.getAllMovies(allMovies);

			view.listMovies(allMovies);

		} else if (menuChoice == 4) { // list movies by genre

			Genre genre = view.getGenre();
			MovieList allMovies;
			MovieList genreMovies;

			movieStore.getAllMovies(allMovies);

			for (int i = 0; i < allMovies.getSize(); ++i) {
				if (allMovies.get(i).getGenre() == genre) {
					genreMovies.add(allMovies.get(i));
				}
			}

			view.listMovies(genreMovies);

		} else if (menuChoice == 5) { // list all movies in reverse
			MovieList allMovies;
			movieStore.getAllMovies(allMovies);

			view.listMoviesReverse(allMovies);

		} else if (menuChoice == 0) { // exit
			running = false;

		} else {
			view.displayMessage("Invalid menu option!");
		}
	} while (running);

#endif

}


Controller::~Controller() {
//	std::cout << "program exited successfully" << std::endl;
}
