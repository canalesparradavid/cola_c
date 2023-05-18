all: cola.o ejemplo.c
	gcc ejemplo.c cola.o -o ejemplo -Wall

cola.o: cola.c cola.h
	gcc cola.c -c -Wall

clean:
	rm -f *.o ejemplo
