CC=gcc
CFLAGS= -Wall -std=c11

App:myCode.c
	$(CC) $(CFLAGS) -lm -lc -lncurses -ltinfo  $^ -o $@

.PHONY: clean

clean:
	rm App


