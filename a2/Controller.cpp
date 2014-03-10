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

#include <iostream>
#include <string>

#include "Movie.h"

using std::string;

/**
 * Constructor handles program flow. Gets user menu choice then acts on that.
 */
Controller::Controller() {

	bool running = true;
	int menuChoice = -1;

	do {
		menuChoice = view.getMenuChoice();

		if (menuChoice == 1) { // add movies

			DynArray movieList;
			view.getMovies(&movieList);

			localMovies.addAllMovies(&movieList);
			masterMovies.addMovies(&movieList);

		} else if (menuChoice == 2) { // delete movie

			string movieTitle = view.deleteMovie();

			Movie* removedMovie = localMovies.removeMovie(movieTitle);

			for (int i = 0; i < localMovies.getSize(); ++i) {
				if (localMovies.movieList[i]->getTitle().compare(movieTitle)
						== 0) {
					DynArray movieToRemove;
					movieToRemove.addMovie(localMovies.movieList[i]);
					masterMovies.removeMovies(&movieToRemove);
					break;
				}
			}

			delete removedMovie;

		} else if (menuChoice == 3) { // list all movies

			view.listMovies(&localMovies);

		} else if (menuChoice == 4) { // list movies by genre

			Genre genre = view.getGenre();
			DynArray genreMovies;

			for (int i = 0; i < localMovies.getSize(); ++i) {
				if (localMovies.movieList[i]->getGenre() == genre) {
					genreMovies.addMovie(localMovies.movieList[i]);
				}
			}

			view.listMovies(&genreMovies);

		} else if (menuChoice == 0) { // exit
			running = false;

		} else {
			view.displayMessage("Invalid menu option!");
		}
	} while (running);

}

Controller::~Controller() {
}
