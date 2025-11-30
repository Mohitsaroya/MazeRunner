CC:=gcc
CFLAGS:=-Wall -std=c11
target:=test.out
source:= test.c maze2.c maze1.c


$(target):$(source)
	$(CC) $(CFLAGS)  $^ -o $@ -lncurses -ltinfo

.PHONY: clean run

run:
	./$(target)

clean:
	rm $(target)
