main: main.o coords.o graph.o
	gcc -o main main.o coords.o graph.o -g -lm

main.o: main.c
	gcc -o main.o -c main.c -g -lm


coords.o: coords.c
	gcc -o coords.o -c coords.c -g -lm

graph.o: graph.c
	gcc -o graph.o -c graph.c -g -lm

tests: tests.o coords.o graph.o
	gcc -o tests tests.o coords.o graph.o -g -lm

tests.o: tests.c
	gcc -o tests.o -c tests.c -g -lm


	
clean:
	rm -rf *.o
	rm -f tests