/*
 * View.cpp
 *
 *  Created on: Jan 31, 2014
 *      Author: jon
 *
 * Manages user I/O in an MVC Media Database program.
 */

#include "View.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "BookFactory.h"
#include "BookInputBehaviour.h"
#include "MovieFactory.h"
#include "MovieInputBehaviour.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;
using std::vector;

View::View() {

	int mediaChoice = -1;

	// determine what type of media user wants to manage
	do {
		mediaChoice = getMediaType();
	} while (mediaChoice < 1 || mediaChoice > 2);

	switch (mediaChoice) {
	case 1:
		inputBehaviour = new MovieInputBehaviour;
		mediaFactory = new MovieFactory;
		break;
	case 2:
		inputBehaviour = new BookInputBehaviour;
		mediaFactory = new BookFactory;
		break;
	default:
		break;
	}
}

View::~View() {
	delete inputBehaviour;
	delete mediaFactory;

}

int View::getMediaType() {
	cout << endl;
	cout << "Would you like to manage Movies or Books?" << endl;
	cout << "( 1 )  Movies" << endl;
	cout << "( 2 )  Books" << endl;

	return getInt();
}

/**
 * Displays program main menu to the user and gets user selection
 * @return
 */
int View::getMenuChoice() {
	cout << endl;
	cout << "( 1 )  Add media" << endl;
	cout << "( 2 )  Delete an item" << endl;
	cout << "( 3 )  List all media" << endl;
	cout << "( 4 )  List all media in reverse" << endl;
	cout << "( 0 )  Exit" << endl;

	return getInt();
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
 * Get a user specified amount of media items from the user
 * @param mediaList
 */
void View::getMedia(List<Media*>& mediaList) {
	cout << endl;
	cout << "Enter the number of items to enter:" << endl;
	int numItems = getInt();

	for (int j = 0; j < numItems; ++j) {

		vector<void*> values;
		inputBehaviour->getMediaData(values);

		Media* media;
		mediaFactory->createData(values, &media);

		mediaList += media;
//		delete media;
	}

}

/**
 * Get the title of a media item to remove from the user
 * @return
 */
string View::deleteMedia() {
	cout << endl;
	cout << "Enter the item's title to remove" << endl;
	return getString();
}

/**
 * Output an array of items to the user
 * @param medias
 */
const void View::listMedia(List<Media*>& medias) {

	for (int i = 0; i < medias.getSize(); ++i) {
		Media* media = medias.get(i);
		cout << endl;
		cout << *media;
	}

}

const void View::listMediaReverse(List<Media*>& medias) {
	for (int i = medias.getSize() - 1; i > -1; --i) {
		Media* media = medias.get(i);
		cout << endl;
		cout << *media;
	}
}

/**
 * Display a message to the user
 * @param s
 */
void View::displayMessage(const string& s) {
	cout << s << endl;
}
