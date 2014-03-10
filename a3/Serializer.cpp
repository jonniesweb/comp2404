/*
 * Serializer.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: jon
 */

#include <cstdio>
#include <string>
#include <string.h>
#include "Serializer.h"
#include <iostream>

using std::cout;

Serializer::Serializer() {
	// TODO Auto-generated constructor stub

}

Serializer::~Serializer() {
	// TODO Auto-generated destructor stub
}

void Serializer::serialize(List<Movie>& movieList, UpdateType& action, string& serialStr) {
	Movie& movie = movieList.get(0);
	char buffer [100];

	char** title = 0;
	int updateType = updateTypeToInt(action);
	int genre = GenreToInt(movie.getGenre());

//	stringToChar(movie->getTitle(), title);
	char output[movie.getTitle().size()+1];
	strcpy(output, movie.getTitle().c_str());

	sprintf(buffer, "*%s*%d*%d*", output, movie.getYear(), 1);

	charToString(buffer, serialStr);

	serialStr = string(buffer);

}

void Serializer::deserialize(string& serialStr, UpdateType& action, List<Movie>& movieList) {


}

void Serializer::charToString(char* input, string& output) {
//	output = new string(input);
}

void Serializer::stringToChar(string& input, char** output) {
	char* tab2 = new char[1024];
	strcpy(tab2, input.c_str());
	output = &tab2;

}

int Serializer::updateTypeToInt(UpdateType& updateType) {
	switch (updateType) {
		case DB_ADD:
			return 0;
			break;
		case DB_DELETE:
			return 1;
			break;
		default:
			return -1;
			break;
	}
	return -1;
}

UpdateType Serializer::intToUpdateType(int updateType) {
	switch (updateType) {
		case 0:
			return DB_ADD;
			break;
		case 1:
			return DB_DELETE;
		default:
			break;
	}
	return DB_ADD;
}

int Serializer::GenreToInt(Genre genre) {
	switch (genre) {
		case COMEDY:
			return 1;
			break;
		case DRAMA:
			return 2;
			break;
		case ACTION:
			return 3;
			break;
		case HORROR:
			return 4;
			break;
		case SF:
			return 5;
			break;
		case ADVENTURE:
			return 6;
			break;
		case WESTERN:
			return 7;
			break;
		default:
			return -1;
			break;
	}
	return -1;
}

Genre Serializer::intToGenre(int genre) {
	switch (genre) {
		case 1:
			return COMEDY;
			break;
		case 2:
			return DRAMA;
			break;
		case 3:
			return ACTION;
			break;
		case 4:
			return HORROR;
			break;
		case 5:
			return SF;
			break;
		case 6:
			return ADVENTURE;
			break;
		case 7:
			return WESTERN;
			break;
		default:
			return UNKNOWN;
		}
}
