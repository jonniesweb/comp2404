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

	void serialize(List<Movie*>& movieList, UpdateType& action, string& serialStr);
	void deserialize(string& serialStr, UpdateType& action, List<Movie*>& movieList);

private:
	static void charToString(char* input, string& output);
	static void stringToChar(string& input, char** output);
	static int updateTypeToInt(UpdateType& updateType);
	static UpdateType intToUpdateType(int);
	static int GenreToInt(Genre);
	static Genre intToGenre(int);
};

#endif /* SERIALIZER_H_ */
