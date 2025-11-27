CC=gcc
CFLAGS= -Wall -std=c11

App:myCode.o Fun.o Fun.h
	$(CC) $(CFLAGS) -lm -lc -lncurses -ltinfo  $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean

clean:
	rm App *.o




