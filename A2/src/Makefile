#################################
# Author: Mohit Saroya
# File: Makefile
# Description: Makefile to compile the MazeRunner game
#################################
CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses

SRC = main.c interface.c gameCards.c level1.c level2.c movement.c maze.c npc.c
OBJ = $(SRC:.c=.o)
TARGET = appGame

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)
	rm -f *.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean doc

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

doc:
	cd .. && doxygen Doxyfile
