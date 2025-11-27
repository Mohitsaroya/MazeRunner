CC=gcc
CFLAGS=-Wall -g -std=c11

App:myCode.o module1.o testUnit.o module1.h testUnit.h
	$(CC) $(CFLAGS) -lm -lc $^ -o $@ -lcunit
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@
.PHONY:clean

clean:
	rm *.o App

