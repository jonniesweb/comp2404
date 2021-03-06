/*
 * View.cpp
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 *
 * Manages user I/O in an MVC Movie Database program.
 */

#include "View.h"

#include <iostream>
#include <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;

View::View() {
}

View::~View() {

}

/**
 * Displays program main menu to the user and gets user selection
 * @return
 */
int View::getMenuChoice() {
	cout << endl;
	cout << "( 1 )  Add movies" << endl;
	cout << "( 2 )  Delete a movie" << endl;
	cout << "( 3 )  List all movies" << endl;
	cout << "( 4 )  List movies by genre" << endl;
	cout << "( 0 )  Exit" << endl;

	return getInt();
}

/**
 * Display a list of genres and get a chosen genre from the user
 * @return
 */
Genre View::getGenre() {

	cout << endl;
	cout << "Please specify a genre:" << endl;
	cout << "(1) Comedy" << endl;
	cout << "(2) Drama" << endl;
	cout << "(3) Action" << endl;
	cout << "(4) Horror" << endl;
	cout << "(5) Science-Fiction" << endl;
	cout << "(6) Adventure" << endl;
	cout << "(7) Western" << endl;

	int value = getInt();
	switch (value) {
	case 1:
		return COMEDY;
		break;
	case 2:
		return DRAMA;
		break;
	case 3:
		return ACTION;
		break;
	case 4:
		return HORROR;
		break;
	case 5:
		return SF;
		break;
	case 6:
		return ADVENTURE;
		break;
	case 7:
		return WESTERN;
		break;
	default:
		return UNKNOWN;
	}
}

/**
 * Gets a string from the user
 * @return
 */
string View::getString() {
	string title;
	getline(cin, title);
	return title;
}

/**
 * Gets an int from the user
 * @return
 */
int View::getInt() {
	int i;
	string s;

	getline(cin, s);
	stringstream ss(s);
	ss >> i;
	return i;
}

/**
 * Gets the user to create a movie
 * @return
 */
Movie* View::getMovie() {

	cout << endl;
	cout << "Enter movie title:" << endl;
	string title = getString();

	cout << endl;
	cout << "Enter movie year:" << endl;
	int year = getInt();

	Genre genre = getGenre();

	return new Movie(title, year, genre);
}

/**
 * Get a user specified amount of movies from the user
 * @param movies
 */
void View::getMovies(DynArray* movies) {
	cout << endl;
	cout << "Enter the number of movies to enter:" << endl;
	int numMovies = getInt();

	for (int j = 0; j < numMovies; ++j) {
		movies->addMovie(getMovie());
	}

}

/**
 * Get the title of a movie to remove from the user
 * @return
 */
string View::deleteMovie() {
	cout << endl;
	cout << "Enter the movie's title to remove" << endl;
	return getString();
}

/**
 * Output an array of movies to the user
 * @param movies
 */
void View::listMovies(DynArray* movies) {
	for (int i = 0; i < movies->getSize(); ++i) {
		cout << endl;
		cout << "Title: " << movies->movieList[i]->getTitle() << endl;
		cout << "Year:  " << movies->movieList[i]->getYear() << endl;
		cout << "Genre: " << genreToString(movies->movieList[i]->getGenre())
				<< endl;
	}

}

/**
 * Convert a Genre type to a string
 * @param genre
 * @return
 */
string View::genreToString(Genre genre) {
	switch (genre) {
	case COMEDY:
		return "Comedy";
		break;

	case ACTION:
		return "Action";
		break;

	case HORROR:
		return "Horror";
		break;

	case DRAMA:
		return "Drama";

	case SF:
		return "Science-Fiction";
		break;

	case ADVENTURE:
		return "Adventure";
		break;

	case WESTERN:
		return "Western";
		break;

	case UNKNOWN: // cascade down
	default:
		return "Unknown";
		break;
	}
}

/**
 * Display a message to the user
 * @param s
 */
void View::displayMessage(string s) {
	cout << s << endl;
}
