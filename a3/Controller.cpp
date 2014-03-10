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
#include <cstdlib>
#include <string>

#include "Movie.h"
#include "Serializer.h"
#include "MovieList.h"

using std::string;
using std::cout;
using std::endl;

/**
 * Constructor handles program flow. Gets user menu choice then acts on that.
 */
Controller::Controller() {

//	Movie* m = new Movie("t", 1, COMEDY);
//	Movie* n = new Movie("z", 1, COMEDY);
//
//	MovieList list;
//	list.add(*m);
//	list.add(*n);
//
//	cout << list.get(0).getTitle() << endl;
//	cout << list.get(1).getTitle() << endl;
//	list.set(1, *m);
//
//	cout << list.remove(0).getTitle() << endl;
//	cout << list.remove(0).getTitle() << endl;



#if 0
	Serializer s;
	Movie* m = new Movie("test", 1, COMEDY);
	List<Movie*> list;
	list.add(&m);

	string str;
	UpdateType type = DB_ADD;

	s.serialize(list, type, str);

	std::cout << str;

	delete m;
#endif


#if 0

	bool running = true;
	int menuChoice = -1;

	do {
		menuChoice = view.getMenuChoice();

		if (menuChoice == 1) { // add movies

			List<Movie*> newMovies;
			view.getMovies(&newMovies);

			movieStore.addMovies(&newMovies);

		} else if (menuChoice == 2) { // delete movie

			List<Movie*> removedMovies;
			string movieTitle = view.deleteMovie();

			List<Movie*> movieList;
			view.getMovies(&movieList);

			for (int i = 0; i < movieList.getSize(); ++i) {
				if ((*movieList.get(i))->getTitle().compare(movieTitle) == 0) {
					removedMovies.add(movieList.get(i));
				}
			}

			movieStore.removeMovies(&removedMovies);

		} else if (menuChoice == 3) { // list all movies

			List<Movie*> allMovies;
			movieStore.getAllMovies(&allMovies);

			view.listMovies(&allMovies);

		} else if (menuChoice == 4) { // list movies by genre

			Genre genre = view.getGenre();
			List<Movie*> allMovies;
			List<Movie*> genreMovies;

			movieStore.getAllMovies(&allMovies);

			for (int i = 0; i < allMovies.getSize(); ++i) {
				if ((*allMovies.get(i))->getGenre() == genre) {
					genreMovies.add(allMovies.get(i));
				}
			}

			view.listMovies(&genreMovies);

		} else if (menuChoice == 5) {

			List<Movie*> allMovies;
			movieStore.getAllMovies(&allMovies);

			// reverse list
			int totalSize = allMovies.getSize();
			for (int i = 0; i < totalSize/2; ++i) {
				Movie* switchMovie = *allMovies.get(i);
				allMovies.set(i, allMovies.get(totalSize - i -1));
				allMovies.set(totalSize - i -1, &switchMovie);
			}

			view.listMovies(&allMovies);

		} else if (menuChoice == 0) { // exit
//			cleanup();
			running = false;

		} else {
			view.displayMessage("Invalid menu option!");
		}
	} while (running);

#endif

}


Controller::~Controller() {
	std::cout << "program exited successfully" << std::endl;
}

void Controller::cleanup() {

	MovieList movies;
	movieStore.getAllMovies(movies);

	for (int i = 0; i < movies.getSize(); ++i) {
		delete &movies.get(i);

	}

}
