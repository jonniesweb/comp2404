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

#include <string>

#include "BookFactory.h"
#include "BookInputBehaviour.h"
#include "Defines.h"
#include "List.h"
#include "Media.h"
#include "MovieFactory.h"
#include "MovieInputBehaviour.h"

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
//	int mediaChoice = -1;
//
//	InputBehaviour* mediaBehaviour;
//	MediaFactory* mediaFactory;
//
//	// determine what type of media user wants to manage
//	do {
//		mediaChoice = view.getMediaType();
//	} while (mediaChoice >= 1 && mediaChoice <= 2);
//
//	switch (mediaChoice) {
//		case 1:
//			mediaBehaviour = new MovieInputBehaviour;
//			mediaFactory = new MovieFactory;
//			break;
//		case 2:
//			mediaBehaviour = new BookInputBehaviour;
//			mediaFactory = new BookFactory;
//			break;
//		default:
//			break;
//	}


	do {
		menuChoice = view.getMenuChoice();

		if (menuChoice == 1) { // add media

			List<Media> newMedia;
			view.getMedia(newMedia);

			storage.update(DB_ADD, newMedia);

		} else if (menuChoice == 2) { // delete media

			List<Media> removedMedia;
			string mediaTitle = view.deleteMedia();

			List<Media> mediaList;
			storage.retrieve(mediaList);

			for (int i = 0; i < mediaList.getSize(); ++i) {
				if (mediaList.get(i).getTitle().compare(mediaTitle) == 0) {
					removedMedia += mediaList.get(i);
				}
			}

			storage.update(DB_DELETE, removedMedia);

		} else if (menuChoice == 3) { // list all media

			List<Media> allMedia;
			storage.retrieve(allMedia);

			view.listMedia(allMedia);

		} else if (menuChoice == 4) { // list all media in reverse
			List<Media> allMedia;
			storage.retrieve(allMedia);

			view.listMediaReverse(allMedia);

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
