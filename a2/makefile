CC = g++
CFLAGS = -std=c++11 -Wall

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
View.h


all: mdb

mdb: $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -vfr *.o mdb

