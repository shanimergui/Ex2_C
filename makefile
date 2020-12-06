#!make -f


all: start clean

start: main.c
	gcc -Wall main.c -o main.o
	./main.o

.PHONY: clean
clean:
			rm -f *.o *.a *.so 
