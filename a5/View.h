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
#include "InputBehaviour.h"
#include "MediaFactory.h"


using std::string;

class View {
public:
	View();
	~View();
	int getMediaType();
	const void listMedia(List<Media*>&);
	const void listMediaReverse(List<Media*>&);
	int getMenuChoice();
	void displayMessage(const string&);
	void getMedia(List<Media*>&);
	string deleteMedia();

	static string getString();
	static int getInt();

private:
	void displayMenu();

	InputBehaviour* inputBehaviour;
	MediaFactory* mediaFactory;
};

#endif /* VIEW_H_ */
