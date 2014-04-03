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

class InputBehaviour;
class MediaFactory;

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
	Genre getGenre();

	static string getString();
	static int getInt();

private:

	Movie& getMovie();
	void displayMenu();
	string genreToString(Genre);


	InputBehaviour* mediaBehaviour;
	MediaFactory* mediaFactory;
};

#endif /* VIEW_H_ */
