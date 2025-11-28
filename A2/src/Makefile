CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses

SRC = main.c interface.c gameCards.c level1.c movement.c
OBJ = $(SRC:.c=.o)

App: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o App -lncurses

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean

run: App
	./App

clean:
	rm -f App *.o
