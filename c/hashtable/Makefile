
CFLAGS = -Wall -Wextra -std=c2x -pedantic

run: main
	./main

main: libhash.a
main: main.c
	$(CC) -o $@ main.c -lhash -Llib -lm

libhash.a:
	$(MAKE) -C lib $@

clean:
	rm -f main
	$(MAKE) -C lib $@
