CC = gcc
CFLAGS = -Wall
objects = main.o queue.o

main: queue.o main.c
	$(CC) -o main queue.o main.c

executa: main
	./main
	
queue.o: queue.c queue.h
	$(CC) -c queue.c
	
clean:
	rm main $(objects)