CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses

App: main.o
	$(CC) $(CFLAGS) main.o -o App $(LDFLAGS)

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

run: App
	./App

clean:
	rm -f App main.o
