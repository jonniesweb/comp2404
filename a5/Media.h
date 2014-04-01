/*
 * Media.h
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#ifndef MEDIA_H_
#define MEDIA_H_

#include <string>

using std::string;

class Media {
public:
	virtual ~Media();
	string& getTitle();
	int getYear() const;

protected:
	Media(const string& title, const int year);
	string title;
	int year;
};

#endif /* MEDIA_H_ */
