CC:=gcc
CFLAGS:=-Wall -std=c11
target:=test.out
source:= test.c maze2.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -lm -lncurses -ltinfo -o $(TARGET)

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
