CC = clang++
CFLAGS = -Wall -g3 

SRC= \
Controller.cpp \
Controller.h   \
List.h         \
List.cpp       \
Main.cpp       \
Movie.cpp      \
Movie.h        \
MovieList.cpp  \
Serializer.cpp \
Server.cpp     \
Server.h       \
Storage.cpp    \
Storage.h      \
View.cpp       \
View.h         \
AbstractList.h \



all: mdb

#mdb: $(SRC)
#	$(CC) $(CFLAGS) -o $@ $(SRC)

mdb: clean
	$(CC) $(CFLAGS) -o $@ *.cpp

clean:
	rm -vfr *.o mdb

