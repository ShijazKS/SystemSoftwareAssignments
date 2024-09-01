CC = gcc
CFLAGS = -Wall

all: library_system

library_system: main.o list.o queue.o
	$(CC) $(CFLAGS) -o library_system main.o list.o queue.o

main.o: main.c list.h queue.h
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -f *.o library_system
