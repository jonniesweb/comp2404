OBJ = main.o Animal.o Bird.o Chicken.o Cat.o Pig.o

t06:	$(OBJ) Random.o
	g++ -m32 -o t06 $(OBJ) Random.o

main.o:	main.cc Animal.h Chicken.h 
	g++ -m32 -c main.cc

Animal.o:	Animal.cc Animal.h
	g++ -m32 -c Animal.cc

Bird.o:	Bird.cc Bird.h Animal.h
	g++ -m32 -c Bird.cc

Chicken.o:	Chicken.cc Chicken.h Bird.h
	g++ -m32 -c Chicken.cc

Cat.o:	Cat.cc Cat.h Animal.h
	g++ -m32 -c Cat.cc

Pig.o:	Pig.cc Pig.h Animal.h
	g++ -m32 -c Pig.cc

clean:
	rm -f $(OBJ) t06
