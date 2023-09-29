
SRCS = $(wildcard *.c)

CFLAGS = -O3
DEBUGFLAGS ?= -Wall -Wextra -std=c2x -pedantic
CFLAGS += $(DEBUGFLAGS)
FLAGS = $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

libhash.a: $(SRCS)
	$(COMPILE.c) $^
	$(AR) rcs $@ *.o

clean:
	rm -f *.o libhash.a