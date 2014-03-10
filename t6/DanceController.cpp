/*
 * DanceController.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: jon
 */

#include "DanceController.h"

DanceController::DanceController() {
	// TODO Auto-generated constructor stub

}

DanceController::~DanceController() {
	// TODO Auto-generated destructor stub
}

void DanceController::initData() {
	view.output("How many birds? ");
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		view.output("Name " << i + 1 << ":  ");
		getline(cin, name);
		barn[numAnimals++] = new Bird(name);
	}

	cout << "How many chickens? ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cout << "Name " << i + 1 << ":  ";
		getline(cin, name);
		barn[numAnimals++] = new Chicken(name);
	}

	cout << "How many cats? ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cout << "Name " << i + 1 << ":  ";
		getline(cin, name);
		barn[numAnimals++] = new Cat(name);
	}

	cout << "How many pigs? ";
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		cout << "Name " << i + 1 << ":  ";
		getline(cin, name);
		barn[numAnimals++] = new Pig(name);
	}
}

void DanceController::dance() {

	for (int i = 0; i < numAnimals; i++)
		barn[i]->dance();

}

void DanceController::outputNames() {
	for (int i = 0; i < numAnimals; i++)
		cout << barn[i]->getName() << endl;
}
