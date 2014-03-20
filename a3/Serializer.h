/*
 * Serializer.h
 *
 *  Created on: Mar 7, 2014
 *      Author: jon
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

//#include <string>

#include "Defines.h"
//#include "List.h"
#include "Movie.h"
//#include "Storage.h"

class MovieList;

using std::string;

class Serializer {
public:
	Serializer();
	virtual ~Serializer();

	void serialize(MovieList& movieList, UpdateType& action, string& serialStr);
	void deserialize(string& serialStr, UpdateType& action, MovieList& movieList);

private:
	string getcharacters(const string& str, int start, int& newStart);
	void charToString(char* input, string& output);
	void stringToChar(string& input, char** output);
	char updateTypeToChar(UpdateType& updateType);
	UpdateType charToUpdateType(char);
	int GenreToChar(Genre);
	Genre CharToGenre(const char*);
	int strlen(char *s);
	void reverse(char *s);
	char* intToChar(int);
	int charToInt(const string&);
};

#endif /* SERIALIZER_H_ */
