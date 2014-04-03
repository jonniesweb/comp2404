/*
 * Media.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#include "Media.h"

#include <sstream>

using std::stringstream;
using std::endl;
using std::ostream;

Media::Media(const string& title, const int year) : title(title), year(year) {

}

Media::~Media() {
}

string& Media::getTitle() {
	return title;
}


int Media::getYear() const {
	return year;
}

bool Media::operator==(Media& media) {
	if (media.title.compare(title) == 0 && media.year == year) {
		return true;
	} else {
		return false;
	}
}

/**
 * Return this object as a string representation
 * @return
 */
void Media::print(ostream& ss) const {
	ss << "wut";

}

/**
 * Insert this object into a stream
 * @param os
 * @return
 */
ostream& operator<<(ostream& os, const Media& media) {
	media.print(os);
	return os;
}
