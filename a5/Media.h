/*
 * Media.h
 *
 *  Created on: Mar 31, 2014
 *      Author: jon
 */

#ifndef MEDIA_H_
#define MEDIA_H_

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Media {
public:
	virtual ~Media();
	string& getTitle();
	int getYear() const;
	bool operator==(Media&);
	virtual void print(ostream&) const;
	friend ostream& operator<<(ostream&, const Media&);

protected:
	Media(const string& title, const int year);
	string title;
	int year;
};

#endif /* MEDIA_H_ */
