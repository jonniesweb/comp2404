/*
 * Media.cpp
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#include "Media.h"

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
