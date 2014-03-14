/*
 * Serializer.h
 *
 *  Created on: Mar 7, 2014
 *      Author: jon
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <string>
#include "Storage.h"
#include "List.h"

using std::string;

class Serializer {
public:
	Serializer();
	virtual ~Serializer();

	void serialize(MovieList& movieList, UpdateType& action, string& serialStr);
	void deserialize(string& serialStr, UpdateType& action, MovieList& movieList);

private:
	static void charToString(char* input, string& output);
	static void stringToChar(string& input, char** output);
	static char updateTypeToChar(UpdateType& updateType);
	static UpdateType charToUpdateType(char);
	static int GenreToChar(Genre);
	static Genre CharToGenre(const char*);
	static int strlen(char *s);
	static void reverse(char *s);
	static char* intToChar(int);
	static int charToInt(const string&);
};

#endif /* SERIALIZER_H_ */
