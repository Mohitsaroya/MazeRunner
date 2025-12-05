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
DEBUG_TARGET = appGame_debug

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)
	rm -f *.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: run clean doc debug Mem_valgrind

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(DEBUG_TARGET) *.o

Mem_valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)


debug:
	$(CC) $(CFLAGS) -g -O0 $(SRC) -o $(DEBUG_TARGET) $(LDFLAGS)

doc:
	cd .. && doxygen Doxyfile
