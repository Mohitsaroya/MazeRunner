CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses

SRC = main.c interface.c gameCards.c level1.c level2.c movement.c maze.c npc.c
OBJ = $(SRC:.c=.o)

App: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o App $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean doc

run: App
	./App

clean:
	rm -f App *.o

doc:
	cd .. && doxygen Doxyfile
