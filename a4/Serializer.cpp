/*
 * Serializer.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: jon
 */


#include "Serializer.h"

#include <iostream>
#include <sstream>
#include <string>

//#include "Movie.h"
#include "MovieList.h"

using std::stringstream;

Serializer::Serializer() {
	// TODO Auto-generated constructor stub

}

Serializer::~Serializer() {
	// TODO Auto-generated destructor stub
}

void Serializer::serialize(MovieList& movieList, UpdateType& action, string& serialStr) {

	// put UpdateType into string
	serialStr += updateTypeToChar(action);
	serialStr += '*';

	// loop over all movies, adding them to the list
	int i = 1;
	for (i = 0; i < movieList.getSize(); ++i) {
		Movie& movie = movieList.get(i);
		serialStr += movie.getTitle();
		serialStr += '*';
		serialStr += intToChar(movie.getYear());
		serialStr += '*';
		serialStr += GenreToChar(movie.getGenre());
		serialStr += '*';

	}

}

void Serializer::deserialize(string& serialStr, UpdateType& action, MovieList& movieList) {

	unsigned int i = 2;

	// get update type
	if (serialStr[0] == '0') {
		action = DB_ADD;
	} else if (serialStr[0] == '1') {
		action = DB_DELETE;
	} else if (serialStr[0] == '2') {
		action = DB_RETRIEVE;
	} else {
		std::cerr << "Serializer::deserialize read an invalid UpdateType\n";
	}

	int next;
	// stop when i is more than length of string
	while (i < serialStr.length()) {

		// get title
		string title = getcharacters(serialStr, i, next);
		i = next + 1;

		// get year
		int year = charToInt(getcharacters(serialStr, i, next));
		i = next + 1;

		// get genre
		Genre genre = CharToGenre(getcharacters(serialStr, i, next).c_str());
		i = next + 1;

		Movie m(title, year, genre);
		movieList.add(m);
	}

}

string Serializer::getcharacters(const string& str, int start, int& newStart) {
	int i = 0;
	while (str[start+i] != '*') {
		i++;
	}
	newStart = start + i;

	return str.substr(start, i);
}

char Serializer::updateTypeToChar(UpdateType& updateType) {
	switch (updateType) {
	case DB_ADD:
		return '0';
		break;
	case DB_DELETE:
		return '1';
		break;
	default:
		return '2';
		break;
	}
	return -1;
}

UpdateType Serializer::charToUpdateType(char updateType) {
	switch (updateType) {
	case '0':
		return DB_ADD;
		break;
	case '1':
		return DB_DELETE;
	default:
		break;
	}
	return DB_ADD;
}

int Serializer::GenreToChar(Genre genre) {
	switch (genre) {
	case COMEDY:
		return '1';
		break;
	case DRAMA:
		return '2';
		break;
	case ACTION:
		return '3';
		break;
	case HORROR:
		return '4';
		break;
	case SF:
		return '5';
		break;
	case ADVENTURE:
		return '6';
		break;
	case WESTERN:
		return '7';
		break;
	default:
		return '8';
		break;
	}
	return '8';
}

Genre Serializer::CharToGenre(const char* genre) {
	switch (*genre) {
	case '1':
		return COMEDY;
		break;
	case '2':
		return DRAMA;
		break;
	case '3':
		return ACTION;
		break;
	case '4':
		return HORROR;
		break;
	case '5':
		return SF;
		break;
	case '6':
		return ADVENTURE;
		break;
	case '7':
		return WESTERN;
		break;
	default:
		return UNKNOWN;
	}
}

int Serializer::strlen(char *s) {
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

void Serializer::reverse(char *s) {
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

char* Serializer::intToChar(int n) {
	static char s[33];
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	return s;
}

int Serializer::charToInt(const string& str) {
	stringstream stream(str);
	int output;
	stream >> output;
	return output;
}
