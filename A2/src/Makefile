CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses

# Source files
SRC = main.c interface.c gameCards.c level1.c level2.c movement.c maze.c npc.c
# Object files
OBJ = $(SRC:.c=.o)

# App target (unchanged)
App: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o App $(LDFLAGS)



# Pattern rule for .o files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Run targets
.PHONY: run run_maze2 clean doc

run: App
	./App


# Clean target
clean:
	rm -f App maze2 *.o

# Documentation target
doc:
	cd .. && doxygen Doxyfile
