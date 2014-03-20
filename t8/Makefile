CC = g++ 
FLAGS = 

t07:	main.o Student.o List.o 
	$(CC) $(FLAGS) -o t07 main.o Student.o List.o 

main.o:	main.cc Student.h List.h
	$(CC) $(FLAGS) -c main.cc

Student.o:	Student.cc Student.h
	$(CC) $(FLAGS) -c Student.cc

List.o:	List.cc List.h
	$(CC) $(FLAGS) -c List.cc

clean:
	rm -f *.o t07
