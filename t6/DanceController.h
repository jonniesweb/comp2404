/*
 * DanceController.h
 *
 *  Created on: Mar 3, 2014
 *      Author: jon
 */


using namespace std;

#include <string>
#include "defs.h"
#include "Bird.h"
#include "Chicken.h"
#include "Cat.h"
#include "Pig.h"
#include "CLView.h"

#ifndef DANCECONTROLLER_H_
#define DANCECONTROLLER_H_

class DanceController {
public:
	DanceController();
	virtual ~DanceController();
	void initData();
	void dance();
	void outputNames();

private:
	Animal* barn[MAX_ANIMALS];
	int numAnimals = 0;

	int num, c;
	string name;

	CLView view;
};

#endif /* DANCECONTROLLER_H_ */
