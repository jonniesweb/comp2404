CC = clang++
CFLAGS = -Wall -g3 -m32

C_SRC= \
Controller.cpp    \
ClientMain.cpp    \
Movie.cpp         \
MovieList.cpp     \
Serializer.cpp    \
Server.cpp        \
ServerControl.cpp \
Storage.cpp       \
Connection.o      \
View.cpp

S_SRC= \
Controller.cpp    \
Movie.cpp         \
MovieList.cpp     \
Serializer.cpp    \
Server.cpp        \
ServerControl.cpp \
ServerMain.cpp    \
Storage.cpp       \
Connection.o      \
View.cpp

all: clean client server

client:
	$(CC) $(CFLAGS) -o $@ $(C_SRC)

server:
	$(CC) $(CFLAGS) -o $@ $(S_SRC)

clean:
	rm -vfr client server 

