CC = g++
CFLAGS = -Wall -g3 

SRC= \
Controller.cpp \
Controller.h   \
DynArray.cpp   \
DynArray.h     \
Main.cpp       \
Movie.cpp      \
Movie.h        \
Server.cpp     \
Server.h       \
Storage.cpp    \
Storage.h      \
View.cpp       \
View.h         \
AbstractList.h \
List.h         \
List.cpp


all: mdb

#mdb: $(SRC)
#	$(CC) $(CFLAGS) -o $@ $(SRC)

mdb: clean
	$(CC) $(CFLAGS) -o $@ *.cpp

clean:
	rm -vfr *.o mdb

valgrind: mdb
	valgrind --leak-check=full --track-origins=yes ./mdb
