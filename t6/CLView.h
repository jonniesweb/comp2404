/*
 * CLView.h
 *
 *  Created on: Mar 3, 2014
 *      Author: jon
 */

#ifndef CLVIEW_H_
#define CLVIEW_H_

#include <string>

using std::string;

class CLView {
public:
	CLView();
	virtual ~CLView();

	void output(string s);
};

#endif /* CLVIEW_H_ */
