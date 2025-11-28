CC := gcc
CFLAGS := -Wall -std=c11
target := test.out
source := test.c maze2.c

$(target): $(source)
	$(CC) $(CFLAGS) $(source) -lm -lncurses -ltinfo -o $(target)

.PHONY: clean run

run: $(target)
	./$(target)

clean:
	rm -f $(target)
