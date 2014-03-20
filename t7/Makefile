t07:	main.o Student.o List.o 
	g++ -o t07 main.o Student.o List.o 

main.o:	main.cc Student.h List.h
	g++ -c main.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

List.o:	List.cc List.h
	g++ -c List.cc

clean:
	rm -f *.o t07
