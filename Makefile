character: main.o character.o
	g++ -o character main.o character.o

main.o: main.cpp character.h
	g++ -o main.o -c main.cpp

character.o: character.cpp character.h
	g++ -o character.o -c character.cpp
clean:
	-rm -f *.o 
