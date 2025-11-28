CC := gcc
CFLAGS := -Wall -std=c11
TARGET := test.out
SOURCES := test.c maze.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -lm -lncurses -ltinfo -o $(TARGET)

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
